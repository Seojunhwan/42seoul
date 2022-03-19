/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:33:00 by junseo            #+#    #+#             */
/*   Updated: 2022/03/19 20:52:51 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrchr(const char *str, int c)
{
	int	index;

	index = ft_strlen(str);
	while (0 <= index)
	{	
		if (str[index] == c)
			return ((char *)&str[index]);
		index--;
	}
	return (NULL);
}
