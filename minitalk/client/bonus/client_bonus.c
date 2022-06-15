/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:52:26 by junseo            #+#    #+#             */
/*   Updated: 2022/06/15 13:48:02 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

t_request	g_request;

void	condition_validator(int argc, char **argv)
{
	int	i;
	int	is_pid_error;

	i = 0;
	is_pid_error = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Error! need to write as: ./client [PID] [Message]\n", 1);
		exit(1);
	}
	while (argv[1][i] != '\0')
	{
		if (!ft_isdigit(argv[1][i]))
			is_pid_error = 1;
		i++;
	}
	g_request.server_pid = ft_atoi(argv[1]);
	if (g_request.server_pid <= 0 || is_pid_error)
	{
		ft_putstr_fd("is invalid PID!", 1);
		exit(1);
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
		ft_putstr_fd("Success handshake\n", 1);
		sigaction(SIGUSR1, &g_request.receive_action, NULL);
		sigaction(SIGUSR2, &g_request.receive_action, NULL);
		usleep(10);
		send_signal();
	}
}

void	receive_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signo == SIGUSR1)
		send_signal();
	else if (signo == SIGUSR2)
	{
		ft_putstr_fd("Message sent complete\n", 1);
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
