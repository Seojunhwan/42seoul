/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 00:51:28 by junseo            #+#    #+#             */
/*   Updated: 2021/09/22 02:31:50 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	ft_strlen(char *str)
{
	long long	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char		*result;
	char		*temp;
	long long	len;
	int			i;

	if (size <= 0)
	{
		result = ((char *)malloc(1));
		result[0] = 0;
		return (result);
	}
	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	result = (char *)malloc(len + (size - 1) * ft_strlen(sep) + 1);
	temp = ft_strcat(result, strs[0]);
	i = 1;
	while (i < size)
	{
		temp = ft_strcat(temp, sep);
		temp = ft_strcat(temp, strs[i++]);
	}
	*temp = 0;
	return (result);
}
