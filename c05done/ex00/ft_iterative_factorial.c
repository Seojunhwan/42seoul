/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:12:47 by junseo            #+#    #+#             */
/*   Updated: 2021/09/21 19:38:23 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = 1;
	result = 1;
	while (i <= nb)
	{
		result = result * i;
		i++;
	}
	return (result);
}