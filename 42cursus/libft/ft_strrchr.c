/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:33:00 by junseo            #+#    #+#             */
/*   Updated: 2021/11/09 23:13:35 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int i;
	int locate;

	i = 0;
	locate = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			locate = i;
		i++;
	}
	return (&str[locate]);
}
#include <stdio.h>
int main()
{
	printf("%s", ft_strrchr("hihi jm junhwan", 'j'));
	return 0;
}
