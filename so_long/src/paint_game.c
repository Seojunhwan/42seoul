/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:29:02 by junseo            #+#    #+#             */
/*   Updated: 2022/06/21 19:44:24 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	paint_img(t_param *param, char *path, int row, int col)
{
	void	*image;
	int		width;
	int		height;

	image = mlx_xpm_file_to_image(param->mlx, path, &width, &height);
	if (!image)
	{
		printf("failed gen image");
		exit(1);
	}
	mlx_put_image_to_window(param->mlx, param->win, image,
		col * IMG_SIZE, row * IMG_SIZE);
}

void	paint_element(t_param *param, char tile, int row, int col)
{
	paint_img(param, "./assets/land.xpm", row, col);
	if (tile == TILE_COLLECTION)
		paint_img(param, "./assets/collection.xpm", row, col);
	else if (tile == TILE_ENTRANCE)
		paint_img(param, "./assets/exit_close.xpm", row, col);
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

void	paint_game(t_param *param)
{
	int	size_x;
	int	size_y;
	int	i;

	i = 0;
	size_x = param->game->map_width * IMG_SIZE;
	size_y = param->game->map_height * IMG_SIZE;
	param->mlx = mlx_init();
	if (!param->mlx)
	{
		printf("MLX INIT FAILED");
		exit(1);
	}
	param->win = mlx_new_window(param->mlx, size_x, size_y, "Junseo");
	if (!(param->win))
	{
		printf("FAILED GEN WINDOW");
		exit(1);
	}
	while (i < param->game->map_height)
	{
		paint_elements(param, i);
		i++;
	}
}
