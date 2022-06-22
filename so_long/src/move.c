/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:20:33 by junseo            #+#    #+#             */
/*   Updated: 2022/06/22 22:43:49 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_w(t_param *param)
{
	t_game	*game;
	char	tile;

	game = param->game;
	tile = game->map[game->pos.row - 1][game->pos.col];
	if (tile == TILE_WALL)
		return ;
	else if (tile == TILE_LAND)
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	else if (tile == TILE_COLLECTION)
	{
		game->collection--;
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	}
	else if (tile == TILE_ENTRANCE)
	{
		if (game->is_possible_exit)
			game->is_done = 1;
		else
			return ;
	}
	game->pos.row--;
	game->map[game->pos.row][game->pos.col] = TILE_PLAYER;
	game->move_count++;
}

void	move_a(t_param *param)
{
	t_game	*game;
	char	tile;

	game = param->game;
	tile = game->map[game->pos.row][game->pos.col - 1];
	if (tile == TILE_WALL)
		return ;
	else if (tile == TILE_LAND)
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	else if (tile == TILE_COLLECTION)
	{
		game->collection--;
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	}
	else if (tile == TILE_ENTRANCE)
	{
		if (game->is_possible_exit)
			game->is_done = 1;
		else
			return ;
	}
	game->pos.col--;
	game->map[game->pos.row][game->pos.col] = TILE_PLAYER;
	game->move_count++;
}

void	move_s(t_param *param)
{
	t_game	*game;
	char	tile;

	game = param->game;
	tile = game->map[game->pos.row + 1][game->pos.col];
	if (tile == TILE_WALL)
		return ;
	else if (tile == TILE_LAND)
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	else if (tile == TILE_COLLECTION)
	{
		game->collection--;
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	}
	else if (tile == TILE_ENTRANCE)
	{
		if (game->is_possible_exit)
			game->is_done = 1;
		else
			return ;
	}
	game->pos.row++;
	game->map[game->pos.row][game->pos.col] = TILE_PLAYER;
	game->move_count++;
}

void	move_d(t_param *param)
{
	t_game	*game;
	char	tile;

	game = param->game;
	tile = game->map[game->pos.row][game->pos.col + 1];
	if (tile == TILE_WALL)
		return ;
	else if (tile == TILE_LAND)
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	else if (tile == TILE_COLLECTION)
	{
		game->collection--;
		game->map[game->pos.row][game->pos.col] = TILE_LAND;
	}
	else if (tile == TILE_ENTRANCE)
	{
		if (game->is_possible_exit)
			game->is_done = 1;
		else
			return ;
	}
	game->pos.col++;
	game->map[game->pos.row][game->pos.col] = TILE_PLAYER;
	game->move_count++;
}

int	handle_key_down(int keycode, t_param *param)
{
	int	before_count;

	before_count = param->game->move_count;
	if (keycode == KEY_W)
		move_w(param);
	else if (keycode == KEY_A)
		move_a(param);
	else if (keycode == KEY_S)
		move_s(param);
	else if (keycode == KEY_D)
		move_d(param);
	else if (keycode == KEY_ESC)
		handle_force_exit_game(param);
	if (param->game->collection == 0)
		param->game->is_possible_exit = 1;
	temp_paint(param);
	if (before_count != param->game->move_count)
		print_move_count(param->game->move_count);
	if (param->game->is_done)
		handle_complete_game(param);
	if (param->game->collection == 0)
		param->game->is_possible_exit = 1;
	return (0);
}
