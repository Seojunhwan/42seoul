/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:28:45 by junseo            #+#    #+#             */
/*   Updated: 2022/06/15 13:48:11 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	str_len;
	size_t	i;

	if (!s)
		return ;
	i = 0;
	str_len = ft_strlen(s);
	write(fd, s, str_len);
}
