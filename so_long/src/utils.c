/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:55:15 by junseo            #+#    #+#             */
/*   Updated: 2022/06/22 22:44:49 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"

int	handle_exit_game(t_param *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

int	handle_force_exit_game(t_param *param)
{
	printf("END\n");
	handle_exit_game(param);
	exit(0);
}

int	handle_complete_game(t_param *param)
{
	printf("COMPLETE\n");
	handle_exit_game(param);
	exit(0);
}

void	print_move_count(int count)
{
	ft_putstr_fd("MOVE COUNT : ", 1);
	ft_putnbr_fd(count, 1);
	ft_putchar_fd('\n', 1);
}

void	error_handler(char *reason)
{
	printf("ERROR\n%s", reason);
	exit(1);
}
