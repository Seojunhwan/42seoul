/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 13:58:51 by junseo            #+#    #+#             */
/*   Updated: 2021/09/20 11:35:23 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	reculsive(int nb)
{
	char	num;

	if (nb == 0)
		return ;
	reculsive(nb / 10);
	num = nb % 10 + '0';
	write(1, &num, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb > 0)
			reculsive(nb);
		else if (nb < 0)
		{
			write(1, "-", 1);
			reculsive(-(nb));
		}
		else
			write(1, "0", 1);
	}
}
