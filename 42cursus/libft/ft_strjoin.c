/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:22:52 by junseo            #+#    #+#             */
/*   Updated: 2021/11/14 11:28:21 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, (s1_len + s2_len + 1));
	ft_strlcpy(result, (char *)s1, s1_len + 1);
	ft_strlcat(&result[s1_len], (char *)s2, s2_len + 1);
	return (result);
}
