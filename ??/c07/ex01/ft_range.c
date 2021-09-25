/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:22:00 by junseo            #+#    #+#             */
/*   Updated: 2021/09/22 12:32:24 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	len;
	int	i;

	i = 0;
	len = (long long) max - min;
	if (min >= max)
		return (0);
	result = (int *)malloc(sizeof(int) * len);
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = min;
		i++;
		min++;
	}
	return (result);
}
