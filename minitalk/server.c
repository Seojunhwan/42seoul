/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:18:06 by junseo            #+#    #+#             */
/*   Updated: 2022/06/13 16:46:08 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signo, siginfo_t *info, void *context)
{
	static unsigned char	buf[100];
	static int				index;
	static int				count;

	(void)info;
	(void)context;
	if (--count == -1)
	{
		count = 7;
		index++;
	}
	if (signo == SIGUSR1)
		buf[index] |= (1 << count);
	else if (signo == SIGUSR2)
		buf[index] &= ~(1 << count);
	if (buf[index] == 127 || index == 99)
	{
		write(1, buf, index + 1);
		if (buf[index] == 127)
			write(1, "\n", 1);
		ft_bzero(buf, 100);
		index = 0;
	}
}

int	display_pid(void)
{
	char	*pid;
	int		get_pid;

	get_pid = getpid();
	if (get_pid < 0 || 99998 < get_pid)
	{
		write(1, "PID ERROR! PID is out of the range!\n", 36);
		return (0);
	}
	pid = ft_itoa(get_pid);
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

int	main(void)
{
	struct sigaction	act1;
	int					sigusr1_result;
	int					sigusr2_result;

	act1.sa_flags = SA_SIGINFO;
	act1.sa_sigaction = handler;
	if (!(display_pid()))
		exit(1);
	sigusr1_result = sigaction(SIGUSR1, &act1, NULL);
	sigusr2_result = sigaction(SIGUSR2, &act1, NULL);
	if (sigusr1_result == -1 || sigusr2_result == -1)
	{
		write(1, "Sigaction Error!", 16);
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
