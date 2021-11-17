/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:19:22 by junseo            #+#    #+#             */
/*   Updated: 2021/11/16 21:52:26 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_size(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
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
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**release_memory(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	**splitter(char **split, char const *s, char c, size_t max_length)
{
	size_t	str_len;
	size_t	size;
	size_t	current_length;

	current_length = 0;
	while (*s != '\0' && current_length <= max_length)
	{
		if (*s == c)
			s++;
		else
		{
			size = 0;
			str_len = get_strlen(s, c);
			split[current_length] = (char *)malloc(sizeof(char) * str_len + 1);
			if (split[current_length] == NULL)
				return (release_memory(split));
			ft_strlcpy(split[current_length], s, str_len + 1);
			s += str_len;
			current_length++;
		}
	}
	split[current_length] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	max_length;

	if (!s)
		return (NULL);
	while (*s && *s == c)
		s++;
	max_length = calc_size(s, c);
	split = (char **)malloc(sizeof(char *) * (max_length + 2));
	if (split == NULL)
		return (NULL);
	splitter(split, s, c, max_length);
	return (split);
}
