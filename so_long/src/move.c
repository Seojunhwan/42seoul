/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:20:33 by junseo            #+#    #+#             */
/*   Updated: 2022/06/21 23:21:31 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *game)
{
	write(1, "\n", 1);
	write(1, &game->map[game->pos.row][game->pos.col], 1);
	write(1, "\n", 1);
	if (game->map[game->pos.row - 1][game->pos.col] == TILE_WALL)
		return ;
	else if (game->map[game->pos.row - 1][game->pos.col] == TILE_LAND)
	{
		ft_putstr_fd("HELLO",1);
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	}
	else if (game->map[game->pos.row - 1][game->pos.col] == TILE_COLLECTION)
	{
		game->collection--;
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	}
	else if (game->map[game->pos.row - 1][game->pos.col] == TILE_ENTRANCE)
	{
		// need a possible exit exception
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	}
	game->pos.row--;
	game->map[game->pos.row][game->pos.col] = TILE_PLAYER;
	game->move_count++;
}

void	move_a(t_game *game)
{
	ft_putnbr_fd(game->pos.row, 1);
	ft_putnbr_fd(game->pos.col, 1);
}

void	move_s(t_game *game)
{
	ft_putnbr_fd(game->pos.row, 1);
	ft_putnbr_fd(game->pos.col, 1);
}

void	move_d(t_game *game)
{
	ft_putnbr_fd(game->pos.row, 1);
	ft_putnbr_fd(game->pos.col, 1);
}

int	handle_key_down(int keycode, t_param *param)
{	
	ft_putnbr_fd(param->game->pos.col, 1);
	ft_putnbr_fd(param->game->pos.row, 1);
	if (keycode == KEY_W)
		move_w(param->game);
	else if (keycode == KEY_A)
		move_a(param->game);
	else if (keycode == KEY_S)
		move_s(param->game);
	else if (keycode == KEY_D)
		move_d(param->game);
	else if (keycode == KEY_ESC)
		handle_exit_game(param);
	if (param->game->collection == 0)
		param->game->is_possible_exit = 1;
	temp_paint(param);
	for(int i = 0; i < param->game->map_height; i += 1)
	{
		ft_putstr_fd(param->game->map[i], 1);
		write(1, "\n", 1);
	}
	return (0);
}
