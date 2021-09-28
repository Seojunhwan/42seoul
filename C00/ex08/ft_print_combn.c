/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:34:31 by junseo            #+#    #+#             */
/*   Updated: 2021/09/13 21:09:29 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_buf[10];
char	g_first;
char	g_len;

void	print_nbr(void)
{
	write(1, g_buf, g_len + 1);
	write(1, ", ", 2);
}

void	check_for_reculsive(int n, char condition)
{
	if (g_buf[n] == condition)
	{
		if (g_buf[n - 1] == --condition)
			check_for_reculsive(n - 1, condition);
		else
		{
			g_buf[n - 1]++;
			while (n - 1 != g_len)
			{
				g_buf[n] = g_buf[n - 1] + 1;
				n++;
			}
		}
	}
	else
		g_buf[n]++;
}

void	ft_print_combn(int n)
{
	int		i;

	g_first = '0' + 10 - n;
	g_len = n - 1;
	i = 0;
	while (i < n)
	{
		g_buf[i] = '0' + i;
		i++;
	}
	while (g_buf[0] != g_first)
	{
		print_nbr();
		check_for_reculsive(n - 1, '9');
	}
	i = 0;
	while (i < n)
	{
		g_buf[i] = g_first + i;
		i++;
	}
	write(1, g_buf, g_len + 1);
}
