/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:35:14 by junseo            #+#    #+#             */
/*   Updated: 2021/09/21 01:19:27 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort(int ac, char **av)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < ac)
	{
		j = 1;
		while (++j < ac)
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
			{
				tmp = av[j + 1];
				av[j + 1] = av[j];
				av[j] = tmp;
			}
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	ft_sort(ac, av);
	while (--ac)
	{
		while (*av[ac])
			write(1, av[ac]++, 1);
		write(1, "\n", 1);
	}
	return (0);
}
