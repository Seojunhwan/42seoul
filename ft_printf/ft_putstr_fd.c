/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:53:50 by junseo            #+#    #+#             */
/*   Updated: 2022/03/19 19:28:20 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	str_len;
	size_t	i;

	if (!s)
		return ;
	i = 0;
	str_len = ft_strlen(s);
	while (i < str_len)
		ft_putchar_fd(s[i++], fd);
}
