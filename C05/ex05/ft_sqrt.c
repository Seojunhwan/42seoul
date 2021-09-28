/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:07:02 by junseo            #+#    #+#             */
/*   Updated: 2021/09/23 14:53:12 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	square;

	if (nb <= 0)
		return (0);
	square = 1;
	while (square * square < nb)
		square++;
	if (square * square == nb)
		return (square);
	return (0);
}
