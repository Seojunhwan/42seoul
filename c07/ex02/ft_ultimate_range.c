/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 23:58:08 by junseo            #+#    #+#             */
/*   Updated: 2021/09/22 12:40:27 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	result;
	int	*temp;

	i = 0;
	if (min >= max)
		return (0);
	result = max - min;
	*range = (int *)malloc(sizeof(int) * result);
	if (!*range)
		return (-1);
	temp = *range;
	while (min < max)
	{
		*temp = min;
		temp++;
		min++;
	}
	return (result);
}
