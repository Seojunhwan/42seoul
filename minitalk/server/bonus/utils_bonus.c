/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:21:02 by junseo            #+#    #+#             */
/*   Updated: 2022/06/15 13:48:08 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	valid_int(long num)
{
	if (num < -2147483648)
		return (0);
	if (num > 2147483647)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	result;

	i = 0;
	result = 0;
	n = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		if (valid_int(result * n) != 1)
			return (valid_int(result * n));
		i++;
	}
	return ((int)n * result);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = (unsigned char)0;
		i++;
	}
}
