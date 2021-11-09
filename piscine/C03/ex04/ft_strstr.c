/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:37:09 by junseo            #+#    #+#             */
/*   Updated: 2021/09/19 13:41:20 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = i;
		k = 0;
		while (to_find[k] != '\0' && str[j] == to_find[k])
		{
			j++;
			k++;
		}
		if (to_find[k] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
