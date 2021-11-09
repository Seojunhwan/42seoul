/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 17:10:09 by junseo            #+#    #+#             */
/*   Updated: 2021/09/12 14:24:57 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	reculsive(int nb)
{
	char	p_num;

	p_num = '0';
	if (nb == 0)
		return ;
	else
	{
		reculsive(nb / 10);
		p_num += nb % 10;
		write(1, &p_num, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb > 0)
		reculsive(nb);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		reculsive(-(nb));
	}
	else
		write(1, "0", 1);
}
