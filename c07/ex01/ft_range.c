/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:22:00 by junseo            #+#    #+#             */
/*   Updated: 2021/09/21 01:31:47 by junseo           ###   ########.fr       */
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
		return (NULL);
	result = (int *)malloc(sizeof(int) * len);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = min++;
		i++;
	}
	return (result);
}
