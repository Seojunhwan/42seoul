/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:52:26 by junseo            #+#    #+#             */
/*   Updated: 2022/06/14 17:30:54 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_request	g_request;

void	ft_verify_bit(char c, int bit)
{
	usleep(20);
	if ((c >> bit & 1) == 0)
		kill(g_request.server_pid, SIGUSR2);
	else if ((c >> bit & 1) == 1)
		kill(g_request.server_pid, SIGUSR1);
}

void	send_end_signal()
{
	int	bit;

	bit = 8;
	kill(g_request.server_pid, SIGUSR2);
	while (bit--)
	{
		usleep(100);
		kill(g_request.server_pid, SIGUSR1);
	}
	return ;
}

void	send_signal(void)
{
	static int	index;
	static int	bit;

	if (--bit == -1)
		bit = 7;
	if (g_request.message[index] == '\0')
	{
		send_end_signal();
		bit++;
		return ;
	}
	ft_verify_bit(g_request.message[index], bit);
	if (bit == 0)
		index++;
}

void	condition_validator(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Error! need to write as: ./client [PID] [Message]\n", 50);
		exit(0);
	}
	g_request.server_pid = ft_atoi(argv[1]);
	if (g_request.server_pid <= 0)
	{
		write(1, "PID Error!\n", 11);
		exit(0);
	}
}

void	send_handshake(void)
{
	static int	request_count;

	kill(g_request.server_pid, SIGUSR1);

	if (request_count == 15)
	{
		exit(0);
	}
	request_count++;
}

void	handshake_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signo == SIGUSR2)
	{
		usleep(1000000);
		send_handshake();
	}
	else if (signo == SIGUSR1)
	{
		write(1, "success handshake\n", 18);
		sigaction(SIGUSR1, &g_request.receive_action, NULL);
		sigaction(SIGUSR2, &g_request.receive_action, NULL);
		send_signal();
	}
}

void	receive_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signo == SIGUSR1)
	{
		send_signal();
	}
	else if (signo == SIGUSR2)
	{
		write(1, "send success\n", 13);
		exit(0);
	}
}

void	init(char **argv)
{
	g_request.handshake_action.sa_flags = SA_SIGINFO;
	g_request.receive_action.sa_flags = SA_SIGINFO;
	g_request.handshake_action.sa_sigaction = handshake_handler;
	g_request.receive_action.sa_sigaction = receive_handler;
	g_request.message = argv[2];
}

int	main(int argc, char **argv)
{
	condition_validator(argc, argv);
	init(argv);
	sigaction(SIGUSR1, &g_request.handshake_action, NULL);
	sigaction(SIGUSR2, &g_request.handshake_action, NULL);
	send_handshake();
	while (1)
		pause();
	return (0);
}
