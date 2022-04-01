/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:13:43 by junseo            #+#    #+#             */
/*   Updated: 2022/04/01 15:17:55 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned int number, char *format, int fd)
{
	if (number >= 16)
	{
		ft_put_hex((number / 16), format, fd);
		ft_putchar_fd(format[number % 16], fd);
	}
	else
		ft_putchar_fd(format[number], fd);
}

int	ft_hex_printer(va_list *ap, int uppercase)
{
	int	len;
	int	number;

	len = 0;
	number = (unsigned int)va_arg(*ap, unsigned int);
	if (uppercase == 1)
		ft_put_hex(number, "0123456789ABCDEF", 1);
	else if (uppercase == 0)
		ft_put_hex(number, "0123456789abcdef", 1);
	if (number == 0)
		len += 1;
	while (number)
	{
		number /= 16;
		len += 1;
	}
	return (len);
}
