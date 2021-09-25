/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 22:30:09 by junseo            #+#    #+#             */
/*   Updated: 2021/09/25 22:33:28 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	if_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i++])
			return (1);
	}
	return (0);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	arr_len(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (if_charset(str[i], charset))
		i++;
	while (str[i] != '\0')
	{
		if (if_charset(str[i], charset))
		{
			count++;
			while (if_charset(str[i], charset))
				i++;
		}
		i++;
	}
	return (count);
}

void	put_str(char *result, int i, int j, char *str)
{
	int	k;

	k = 0;
	while (j < i)
	{
		result[k] = str[j];
		k++;
		j++;
	}
	result[k] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		index;

	i = 0;
	index = 0;
	result = (char **)malloc(sizeof(char *) * (arr_len(str, charset) + 2));
	while (if_charset(str[i], charset))
		i++;
	while (str[i] != '\0')
	{
		if (!if_charset(str[i], charset))
		{
			j = i;
			while (str[i] != '\0' && !if_charset(str[i], charset))
				i++;
			result[index] = (char *)malloc(i - j + 1);
			put_str(result[index++], i, j, str);
		}
		i++;
	}
	result[index] = 0;
	return (result);
}
