/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:19:22 by junseo            #+#    #+#             */
/*   Updated: 2021/11/15 16:04:16 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	calc_size(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	get_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	str_len;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = calc_size(s, c);
	split = (char **)malloc(sizeof(char *) * (j + 2));
	if (split == NULL)
		return (NULL);
	while (*s == c)
		s++;
	while (*s != '\0' && i <= j)
	{
		if (*s == c)
			s++;
		else
		{
			size = 0;
			str_len = get_strlen(s, c);
			split[i] = (char *)malloc(sizeof(char) * str_len + 1);
			while (size < str_len)
			{
				split[i][size] = *s;
				size++;
				s++;
			}
			split[i][size] = '\0';
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
// int main()
// {
// 	int i;

// 	i = 0;
// 	char **result =	ft_split("\0aa\0bbb", '\0');
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n",result[i]);
// 		result++;
// 	}
// 	return 0;
// }
