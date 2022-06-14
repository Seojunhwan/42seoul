/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:18:22 by junseo            #+#    #+#             */
/*   Updated: 2022/06/14 20:30:18 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_request	g_request;

void	ft_verify_bit(char c, int bit)
{
	usleep(20);
	if ((c >> bit & 1) == 0)
		kill(g_request.server_pid, SIGUSR2);
	else if ((c >> bit & 1) == 1)
		kill(g_request.server_pid, SIGUSR1);
}

void	send_end_signal(void)
{
	static int	bit;

	if (--bit == -1)
		bit = 7;
	if (bit == 7)
		kill(g_request.server_pid, SIGUSR2);
	else
		kill(g_request.server_pid, SIGUSR1);
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

void	send_handshake(void)
{
	static int	request_count;

	kill(g_request.server_pid, SIGUSR1);
	if (request_count == 15)
	{
		write(1, "Server error\n", 13);
		exit(0);
	}
	request_count++;
}
