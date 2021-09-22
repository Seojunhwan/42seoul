/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:37:30 by junseo            #+#    #+#             */
/*   Updated: 2021/09/22 20:56:27 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int			g_to_index;

void	calc_strs_len(unsigned int *from_len, unsigned int *to_len, char *from_base, char *to_base)
{
	int i;

	i = 0;
	while (from_base[i])
		i++;
	*from_len = i;
	i = 0;
	while (to_base[i])
		i++;
	*to_len = i;
}

int calc_arr_size(unsigned int nbr, char *base, unsigned int to_len)
{
	int arr_size;

	arr_size = 0;
	if (nbr >= to_len)
	{
		calc_arr_size(nbr / to_len, base, to_len);
		calc_arr_size(nbr % to_len, base, to_len);
	}
	else
		arr_size++;
	return (arr_size);
}

void	recursive(unsigned int nbr, char *base, char *result, unsigned int to_len)
{
	if (nbr >= to_len)
	{
		recursive(nbr / to_len, base, result, to_len);
		recursive(nbr % to_len, base, result, to_len);
	}
	else
	{
		result[g_to_index] = base[nbr];
		g_to_index++;
	}
}

int	check_to_base(char *base)
{
	int	condition;
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i] != '\0')
	{	
		j = 0;
		condition = 0;
		while (base[j] != '\0')
		{
			if (base[j] == base[i] || base[j] == '+' || base[j] == '-'
				|| base[j] == ' ' || (base[j] >= 9 && base[j] <= 13))
				condition++;
			j++;
		}
		if (condition > 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base, char *result, unsigned int to_len)
{
	g_to_index = 0;
	if (nbr < 0)
	{
		result[g_to_index] = '-';
		g_to_index++;
		recursive(-(nbr), base, result, to_len);
	}
	else
		recursive(nbr, base, result, to_len);
	result[g_to_index] = 0;
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	check_from_base(char *base)
{
	int	condition;
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = 0;
		condition = 0;
		while (base[j] != '\0')
		{
			if (base[j] == base[i] || base[j] == '+' || base[j] == '-'
				|| base[j] == ' ' || (base[j] >= 9 && base[j] <= 13))
				condition++;
			j++;
		}
		if (condition > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_get_idx(char c, char *base, unsigned int from_len)
{
	unsigned int	i;

	i = 0;
	while (i < from_len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base, unsigned int from_len)
{
	int	i;
	int	n;
	int	idx;
	int	result;

	i = 0;
	n = 1;
	result = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			n *= -1;
	while (str[i] != '\0')
	{
		idx = ft_get_idx(str[i++], base, from_len);
		if (idx == -1)
			break ;
		result *= from_len;
		result += idx;
	}
	return (result * n);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int					base_10_num;
	int					arr_size;
	unsigned int		to_len;
	unsigned int		from_len;
	char				*result;
	
	arr_size = 0;
	if (check_to_base(base_to) && check_from_base(base_from))
	{
		calc_strs_len(&from_len, &to_len, base_from, base_to);
		base_10_num = ft_atoi_base(nbr, base_from, from_len);
		if (base_10_num < 0)
		{
			arr_size++;
			arr_size += calc_arr_size(-(base_10_num), base_to, to_len);
		}
		else
			arr_size = calc_arr_size(base_10_num, base_to, to_len);
		result = (char *)malloc(sizeof(char) * arr_size + 1);
		if (!result)
			return (NULL);
		ft_putnbr_base(base_10_num, base_to, result, to_len);
		return (result);
	}
	return (NULL);
}