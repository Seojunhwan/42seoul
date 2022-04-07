/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:39:46 by junseo            #+#    #+#             */
/*   Updated: 2022/04/07 15:30:46 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_printer(va_list *ap)
{
	ft_putchar_fd((char)va_arg(*ap, int), 1);
	return (1);
}

int	ft_str_printer(va_list *ap)
{
	int		len;
	char	*str;

	len = 0;
	str = (char *)va_arg(*ap, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		len = 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	return (len);
}
