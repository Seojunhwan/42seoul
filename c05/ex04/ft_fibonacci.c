/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:03:58 by junseo            #+#    #+#             */
/*   Updated: 2021/09/21 19:39:18 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
