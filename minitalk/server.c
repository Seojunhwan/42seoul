/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:18:06 by junseo            #+#    #+#             */
/*   Updated: 2022/06/14 17:21:43 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_request	g_request;

void	receive_handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	buf[100];
	static int				index;
	static int				bit;

	(void)context;
	if (info->si_pid != g_request.current_client)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	if (--bit == -1)
	{
		bit = 7;
		index++;
	}
	if (signo == SIGUSR1)
		buf[index] |= (1 << bit);
	else if (signo == SIGUSR2)
		buf[index] &= ~(1 << bit);
	if (buf[index] == 127 || index == 99)
	{
		write(1, buf, index + 1);
		if (buf[index] == 127)
			g_request.is_done = 1;
		ft_bzero(buf, 100);
		index = 0;
	}
	if (g_request.is_done == 1)
	{
		write(1, "\n", 1);
		sigaction(SIGUSR1, &g_request.handshake_action, NULL);
		sigaction(SIGUSR2, &g_request.handshake_action, NULL);
		g_request.current_client = 0;
		g_request.is_done = 0;
		kill(info->si_pid, SIGUSR2);
	}
	else
		kill(g_request.current_client, SIGUSR1);
}

int	display_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	if (!pid)
	{
		write(1, "PID Malloc Error\n", 17);
		free(pid);
		return (0);
	}
	write(1, "PID : ", 6);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
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
	g_request.handshake_action.sa_flags = SA_SIGINFO;
	g_request.receive_action.sa_flags = SA_SIGINFO;
	g_request.handshake_action.sa_sigaction = handshake_handler;
	g_request.receive_action.sa_sigaction = receive_handler;
	g_request.current_client = 0;
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
