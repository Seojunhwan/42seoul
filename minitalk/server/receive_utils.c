/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:43:04 by junseo            #+#    #+#             */
/*   Updated: 2022/06/15 13:32:02 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_request	g_request;

void	print_message(void)
{
	write(1, g_request.message, g_request.index + 1);
	if (g_request.message[g_request.index] == 127)
		g_request.is_done = 1;
	ft_bzero(g_request.message, 100);
	g_request.index = 0;
}

void	send_end_message(pid_t client_pid)
{
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &g_request.handshake_action, NULL);
	sigaction(SIGUSR2, &g_request.handshake_action, NULL);
	g_request.current_client = 0;
	g_request.is_done = 0;
	kill(client_pid, SIGUSR2);
}

void	receive_handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid != g_request.current_client)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	if (--g_request.bit == -1)
	{
		g_request.bit = 7;
		g_request.index++;
	}
	if (signo == SIGUSR1)
		g_request.message[g_request.index] |= (1 << g_request.bit);
	else if (signo == SIGUSR2)
		g_request.message[g_request.index] &= ~(1 << g_request.bit);
	if (g_request.message[g_request.index] == 127 || g_request.index == 99)
		print_message();
	if (g_request.is_done == 1)
		send_end_message(info->si_pid);
	else
		kill(g_request.current_client, SIGUSR1);
}
