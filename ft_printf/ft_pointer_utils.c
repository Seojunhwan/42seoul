/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:14:23 by junseo            #+#    #+#             */
/*   Updated: 2022/04/01 15:17:23 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_put_pointer(ptr / 16);
		ft_put_pointer(ptr % 16);
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[ptr], 1);
	}
}

int	ft_pointer_printer(va_list *ap)
{
	int			len;
	uintptr_t	ptr;

	len = 0;
	ptr = (uintptr_t)va_arg(*ap, void *);
	ft_putstr_fd("0x", 1);
	len += 2;
	if (ptr == 0)
	{
		ft_putchar_fd('0', 1);
		len += 1;
	}
	ft_put_pointer(ptr);
	while (ptr)
	{
		ptr /= 16;
		len += 1;
	}
	return (len);
}
