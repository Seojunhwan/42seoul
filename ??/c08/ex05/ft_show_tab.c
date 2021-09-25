/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:15:58 by junseo            #+#    #+#             */
/*   Updated: 2021/09/22 16:20:48 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_size(int nb)
{
	char	num;

	if (nb == 0)
		return ;
	print_size(nb / 10);
	num = nb % 10 + '0';
	write(1, &num, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, par[i].size);
		write(1, "\n", 1);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			print_size(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, par[i].size);
		write(1, "\n", 1);
		i++;
	}
}
