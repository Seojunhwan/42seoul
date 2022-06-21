/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:36:09 by junseo            #+#    #+#             */
/*   Updated: 2022/06/21 19:48:29 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_param	*param;
	char	*map_path;

	map_path = argv[1];
	argument_checker(argc, map_path);
	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		error_handler(ERROR_MALLOC);
	init(param);
	parse_map(param->game, map_path);
	check_map(param->game);
	paint_game(param);
	mlx_loop(param->mlx);
	return (0);
}
