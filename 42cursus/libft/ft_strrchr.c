/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:33:00 by junseo            #+#    #+#             */
/*   Updated: 2021/11/19 22:40:32 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	index;

	index = ft_strlen(str);
	while (0 <= index)
	{	
		if (str[index] == c)
			return (&str[index]);
		index--;
	}
	return (NULL);
}
