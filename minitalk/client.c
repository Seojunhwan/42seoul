/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:52:26 by junseo            #+#    #+#             */
/*   Updated: 2022/06/13 15:19:09 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_verify_bit(int server_pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if ((c >> bit & 1) == 0)
			kill(server_pid, SIGUSR2);
		else if ((c >> bit & 1) == 1)
			kill(server_pid, SIGUSR1);
		usleep(100);
	}
	return ;
}

void	send_signal(int server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_verify_bit(server_pid, str[i]);
		i++;
	}
	return ;
}

void	send_end_signal(int server_pid)
{
	int	bit;

	bit = 7;
	kill(server_pid, SIGUSR2);
	while (bit--)
	{
		usleep(100);
		kill(server_pid, SIGUSR1);
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		write(1, "Error! need to write as: ./client [PID] [Message]\n", 50);
		exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		write(1, "PID Error!\n", 11);
		exit(0);
	}
	send_signal(server_pid, argv[2]);
	send_end_signal(server_pid);
	return (0);
}
