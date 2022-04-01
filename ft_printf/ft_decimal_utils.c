/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:13:11 by junseo            #+#    #+#             */
/*   Updated: 2022/04/01 15:15:16 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unnbr(unsigned int number, int fd)
{
	if (number >= 10)
	{
		ft_put_unnbr(number / 10, fd);
		ft_putchar_fd((number % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd(number + '0', fd);
	}
}

int	ft_decimal_printer(va_list *ap)
{
	int	number;
	int	len;

	number = va_arg(*ap, int);
	ft_putnbr_fd(number, 1);
	len = 0;
	if (number == 0)
		len += 1;
	else if (number < 0)
	{
		number *= -1;
		len += 1;
	}
	while (number)
	{
		number /= 10;
		len += 1;
	}
	return (len);
}

int	ft_unsigned_decimal_printer(va_list *ap)
{
	unsigned int	number;
	int				len;

	number = (unsigned int)va_arg(*ap, int);
	if (number == 0)
		len = write(1, "0", 1);
	else
		ft_put_unnbr(number, 1);
	len = 0;
	if (number == 0)
		len += 1;
	while (number)
	{
		number /= 10;
		len += 1;
	}
	return (len);
}
