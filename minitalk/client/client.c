/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:52:26 by junseo            #+#    #+#             */
/*   Updated: 2022/06/14 22:37:24 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_request	g_request;

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
		usleep(25);
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
	g_request.handshake_action.sa_flags = SA_SIGINFO | SA_NODEFER;
	g_request.receive_action.sa_flags = SA_SIGINFO | SA_NODEFER;
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
