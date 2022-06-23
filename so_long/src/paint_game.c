/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:29:02 by junseo            #+#    #+#             */
/*   Updated: 2022/06/23 21:41:04 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	paint_img(t_param *param, char *path, int row, int col)
{
	void	*image;
	int		width;
	int		height;

	image = mlx_xpm_file_to_image(param->mlx, path, &width, &height);
	if (!image)
		error_handler("image gen failed!");
	mlx_put_image_to_window(param->mlx, param->win, image,
		col * IMG_SIZE, row * IMG_SIZE);
	mlx_destroy_image(param->mlx, image);
}

void	paint_element(t_param *param, char tile, int row, int col)
{
	paint_img(param, "./assets/land.xpm", row, col);
	if (tile == TILE_COLLECTION)
		paint_img(param, "./assets/collection.xpm", row, col);
	else if (tile == TILE_ENTRANCE)
	{
		if (param->game->is_possible_exit)
			paint_img(param, "./assets/exit_open.xpm", row, col);
		else
			paint_img(param, "./assets/exit_close.xpm", row, col);
	}
	else if (tile == TILE_PLAYER)
		paint_img(param, "./assets/player.xpm", row, col);
	else if (tile == TILE_WALL)
		paint_img(param, "./assets/wall.xpm", row, col);
}

void	paint_elements(t_param *param, int row)
{
	int		col;
	char	*line;

	col = 0;
	line = param->game->map[row];
	while (col < param->game->map_width)
	{
		paint_element(param, line[col], row, col);
		col++;
	}
}

void	call_paint_elements(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->game->map_height)
	{
		paint_elements(param, i);
		i++;
	}
}

void	paint_game(t_param *param)
{
	int	size_x;
	int	size_y;

	size_x = param->game->map_width * IMG_SIZE;
	size_y = param->game->map_height * IMG_SIZE;
	param->mlx = mlx_init();
	if (!param->mlx)
		error_handler("mlx init failed");
	param->win = mlx_new_window(param->mlx, size_x, size_y, "Junseo");
	if (!(param->win))
		error_handler("window gen failed");
	call_paint_elements(param);
}
