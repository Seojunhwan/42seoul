/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:40:39 by junseo            #+#    #+#             */
/*   Updated: 2021/11/09 23:12:08 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	const char *ptr;
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (0);
}

int main()
{
	char str[]={"hi i am junhwan"};
	ft_strchr(str, 'a');
}
