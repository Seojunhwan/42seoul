/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:36:09 by junseo            #+#    #+#             */
/*   Updated: 2022/06/18 16:43:22 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argcv)
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	void *img7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./assets/land.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./assets/collection.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./assets/player.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", &img_width, &img_height);

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 64);
	mlx_put_image_to_window(mlx, win, img5, 0, 64);
	// mlx_put_image_to_window(mlx, win, img6, 64, 64);
	// mlx_put_image_to_window(mlx, win, img7, 128, 64);
	mlx_loop(mlx);
	return (0);
}