/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:18:06 by junseo            #+#    #+#             */
/*   Updated: 2022/06/15 13:08:54 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_request	g_request;

int	display_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	if (!pid)
	{
		ft_putstr_fd("PID Malloc Error\n", 1);
		free(pid);
		return (0);
	}
	ft_putstr_fd("PID : ", 1);
	ft_putstr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	free(pid);
	return (1);
}

void	handshake_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)signo;
	if (g_request.current_client == 0)
		g_request.current_client = info->si_pid;
	if (g_request.current_client != info->si_pid)
		kill(info->si_pid, SIGUSR2);
	kill(g_request.current_client, SIGUSR1);
	sigaction(SIGUSR1, &g_request.receive_action, NULL);
	sigaction(SIGUSR2, &g_request.receive_action, NULL);
}

void	init(void)
{
	g_request.handshake_action.sa_flags = SA_SIGINFO | SA_NODEFER;
	g_request.receive_action.sa_flags = SA_SIGINFO | SA_NODEFER;
	g_request.handshake_action.sa_sigaction = handshake_handler;
	g_request.receive_action.sa_sigaction = receive_handler;
	g_request.current_client = 0;
	g_request.is_done = 0;
	g_request.bit = 0;
	g_request.index = 0;
	g_request.message = (unsigned char *)malloc(sizeof(char) * 100);
	if (!g_request.message)
	{
		ft_putstr_fd("message buf malloc failed\n", 1);
		exit(1);
	}
}

int	main(void)
{
	if (!(display_pid()))
		exit(1);
	init();
	sigaction(SIGUSR1, &g_request.handshake_action, NULL);
	sigaction(SIGUSR2, &g_request.handshake_action, NULL);
	while (1)
		pause();
	return (0);
}
