/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_base2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:57:59 by junseo            #+#    #+#             */
/*   Updated: 2021/09/22 21:18:00 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	g_to_index;

void	calc_len(int *from_len, int *to_len, char *from_base, char *to_base)
{
	int	i;

	i = 0;
	while (from_base[i])
		i++;
	*from_len = i;
	i = 0;
	while (to_base[i])
		i++;
	*to_len = i;
}

int	calc_arr_size(unsigned int nbr, char *base, unsigned int to_len)
{
	int	arr_size;

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

void	recursive(int nbr, char *base, char *result, int to_len)
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
