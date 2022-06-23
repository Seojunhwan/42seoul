/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:36:09 by junseo            #+#    #+#             */
/*   Updated: 2022/06/23 17:30:59 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_param	*param;
	char	*map_path;

	map_path = argv[1];
	argument_checker(argc, map_path);
	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		error_handler("Param Malloc Failed");
	init(param);
	parse_map(param->game, map_path);
	check_map(param->game);
	paint_game(param);
	mlx_hook(param->win, X_EVENT_KEY_PRESS, 0, &handle_key_down, param);
	mlx_hook(param->win, X_EVENT_KEY_EXIT, 0, &handle_force_exit_game, param);
	mlx_loop(param->mlx);
	mlx_destroy_window(param->mlx, param->win);
	return (0);
}
