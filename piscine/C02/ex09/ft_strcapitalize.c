/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 20:19:33 by junseo            #+#    #+#             */
/*   Updated: 2021/09/18 13:45:50 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_word(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (is_word(str[i]) == 1)
		{
			if (flag && str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			else if (!flag && str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	return (str);
}
