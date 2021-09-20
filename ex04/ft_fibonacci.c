/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:03:58 by junseo            #+#    #+#             */
/*   Updated: 2021/09/20 11:20:58 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	fibo(int index, int a, int b)
{
	if (index == 0)
		return (a);
	if (index == 1)
		return (b);
	return (fibo(index - 1, b, a + b));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (fibo(index, 0, 1));
}

int main()
{
	printf("%d", ft_fibonacci(5));
	return 0;
}
