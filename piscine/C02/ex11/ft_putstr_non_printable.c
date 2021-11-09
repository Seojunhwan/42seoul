/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:37:21 by junseo            #+#    #+#             */
/*   Updated: 2021/09/16 14:37:04 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	write_hex(unsigned char c)
{
	c += '0';
	if (c > '9')
		c += 39;
	write(1, &c, 1);
}

void	calc_hex(unsigned char c)
{
	write(1, "\\", 1);
	write_hex((int)c / 16);
	write_hex((int)c % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (printable(str[i]))
			write(1, &str[i], 1);
		else
			calc_hex(str[i]);
		i++;
	}
}
