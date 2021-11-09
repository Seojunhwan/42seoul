/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:02:57 by junseo            #+#    #+#             */
/*   Updated: 2021/09/21 13:50:29 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned int	g_len;

void	recursive(unsigned int nbr, char *base)
{
	if (nbr >= g_len)
	{
		recursive(nbr / g_len, base);
		recursive(nbr % g_len, base);
	}
	else
		write(1, &base[nbr], 1);
}

int	check_base(char *base)
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
			if (base[j] == base[i] || base[j] == '+' || base[j] == '-')
				condition++;
			j++;
		}
		if (condition > 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	g_len = 0;
	if (check_base(base))
	{
		while (base[g_len])
			g_len++;
		if (nbr < 0)
		{
			write(1, "-", 1);
			recursive(-(nbr), base);
		}
		else
			recursive(nbr, base);
	}
}
