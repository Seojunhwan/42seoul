/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 20:50:25 by junseo            #+#    #+#             */
/*   Updated: 2021/09/21 13:44:07 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		g_len;

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int	condition;
	int	i;
	int	j;

	i = 0;
	g_len = 0;
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
		g_len++;
		i++;
	}
	return (1);
}

int	ft_get_idx(char c, char *base)
{
	int	i;

	i = 0;
	while (i < g_len)
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
	if (check_base(base))
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
			result *= g_len;
			result += idx;
		}
	}
	return (result * n);
}
