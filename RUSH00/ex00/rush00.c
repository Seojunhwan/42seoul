/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 11:27:34 by junseo            #+#    #+#             */
/*   Updated: 2021/09/12 16:19:29 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_col(char *item, int x)
{
	int	col;

	col = 1;
	while (col <= x)
	{
		if (col == 1 || col == x)
			ft_putchar(item[0]);
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
		if (row == 1 || row == y)
			print_col("o-", x);
		else
			print_col("| ", x);
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
