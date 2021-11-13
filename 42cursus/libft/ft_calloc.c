/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:10:26 by junseo            #+#    #+#             */
/*   Updated: 2021/11/13 23:11:59 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	size_t			i;

	i = 0;
	result = (unsigned char *)malloc(size * count);
	if (result == NULL)
		return (NULL);
	while (i < size * count)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
