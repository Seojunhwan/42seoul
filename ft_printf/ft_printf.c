/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:19:28 by junseo            #+#    #+#             */
/*   Updated: 2022/04/01 16:28:55 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_checker(const char *format, va_list *ap)
{
	int	len;

	if (*format == 'c')
		len = ft_char_printer(ap);
	if (*format == 's')
		len = ft_str_printer(ap);
	if (*format == 'p')
		len = ft_pointer_printer(ap);
	if (*format == 'd' || *format == 'i')
		len = ft_decimal_printer(ap);
	if (*format == 'u')
		len = ft_unsigned_decimal_printer(ap);
	if (*format == 'x')
		len = ft_hex_printer(ap, 0);
	if (*format == 'X')
		len = ft_hex_printer(ap, 1);
	if (*format == '%')
	{
		ft_putchar_fd('%', 0);
		len = 1;
	}
	else
		len = 0;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			len += ft_flag_checker(format, &ap);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len += 1;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
