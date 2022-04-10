/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:19:28 by junseo            #+#    #+#             */
/*   Updated: 2022/04/10 19:02:39 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	other_form(char c)
{
	if (c == '%')
		write(1, "%", 1);
	else if (ft_isascii(c))
		write(1, &c, 1);
	else
		return (0);
	return (1);
}

int	ft_flag_checker(char c, va_list *ap)
{
	int	len;

	if (c == 'c')
		len = ft_char_printer(ap);
	else if (c == 's')
		len = ft_str_printer(ap);
	else if (c == 'p')
		len = ft_pointer_printer(ap);
	else if (c == 'd' || c == 'i')
		len = ft_decimal_printer(ap);
	else if (c == 'u')
		len = ft_unsigned_decimal_printer(ap);
	else if (c == 'x')
		len = ft_hex_printer(ap, 0);
	else if (c == 'X')
		len = ft_hex_printer(ap, 1);
	else
		len = other_form(c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	long long	len;

	if (!format)
		return (-1);
	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			len += write(1, &format[i++], 1);
		else
		{
			i++;
			len += ft_flag_checker(format[i++], &ap);
		}
	}
	va_end(ap);
	if (len > 2147483647)
		return (-1);
	return ((int)len);
}
