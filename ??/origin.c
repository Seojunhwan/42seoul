/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:37:30 by junseo            #+#    #+#             */
/*   Updated: 2021/09/22 19:16:03 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static unsigned int	g_to_len;
static int			g_from_len;
static int			g_to_index;
static int			g_arr_size;

void	calc_arr_size(unsigned int nbr, char *base)
{
	while (base[g_to_len])
		g_to_len++;
	if (nbr >= g_to_len)
	{
		calc_arr_size(nbr / g_to_len, base);
		calc_arr_size(nbr % g_to_len, base);
	}
	else
		g_arr_size++;
}

void	recursive(unsigned int nbr, char *base, char *result)
{
	if (nbr >= g_to_len)
	{
		recursive(nbr / g_to_len, base, result);
		recursive(nbr % g_to_len, base, result);
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

void	ft_putnbr_base(int nbr, char *base, char *result)
{
	printf("this is :%d",check_to_base(base));
	printf("\nbase : %s", base);
	if (check_to_base(base))
	{
		g_to_index = 0;
		if (nbr < 0)
		{
			result[g_to_index] = '-';
			g_to_index++;
			recursive(-(nbr), base, result);
		}
		else
			recursive(nbr, base, result);
	}
	else
		return;
	result[g_to_index] = 0;
}


/// TODO 여기  위로는 int to str 입니당

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
		g_from_len++;
		i++;
	}
	return (1);
}

int	ft_get_idx(char c, char *base)
{
	int	i;

	i = 0;
	while (i < g_from_len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	idx;
	int	result;

	i = 0;
	n = 1;
	result = 0;
	if (check_from_base(base))
	{
		while (is_space(str[i]))
			i++;
		while (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				n *= -1;
		while (str[i] != '\0')
		{
			idx = ft_get_idx(str[i++], base);
			if (idx == -1)
				break ;
			result *= g_from_len;
			result += idx;
		}
	}
	else
		return (0);
	return (result * n);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int base_10_num;
	char *result;

	if (base_from[0] == ' ' || base_from[1] == '\0' || base_to[0] == ' ' || base_to[1] == '\0')
		return (NULL);
	g_to_len = 0;
	g_from_len = 0;
	g_arr_size = 0;
	base_10_num = ft_atoi_base(nbr, base_from);
	if (base_10_num < 0)
		{
			g_arr_size++;
			calc_arr_size(-(base_10_num), base_to);
		}
		else
			calc_arr_size(base_10_num, base_to);
	result = (char *)malloc(sizeof(char) * g_arr_size + 1);
	if (!result)
		return (NULL);
	ft_putnbr_base(base_10_num, base_to, result);
	printf("base_10_num : %d\n", base_10_num);
	return (result);
}

void	do_test(char *a, char *b, char *c)
{
	printf("%s",ft_convert_base(a, b,  c));
}

int main()
{
	do_test("1234", "12345-64", "qwertyui");
	do_test("1234", "12345678+", "qwertyuio");
	// do_test("", "", "");
}