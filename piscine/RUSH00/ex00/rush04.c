/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:27:34 by junseo            #+#    #+#             */
/*   Updated: 2021/09/12 16:16:43 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_col(char *item, int x)
{
	int	col;

	col = 1;
	while (col <= x)
	{
		if (col == 1)
			ft_putchar(item[0]);
		else if (col == x)
			ft_putchar(item[2]);
		else
			ft_putchar(item[1]);
		col++;
	}
	ft_putchar('\n');
}

void	print_row(int x, int y)
{
	int	row;

	row = 1;
	while (row <= y)
	{
		if (row == 1)
			print_col("ABC", x);
		else if (row == y)
			print_col("CBA", x);
		else
			print_col("B B", x);
		row++;
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
		print_row(x, y);
	else
		return ;
}