/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:03:04 by junseo            #+#    #+#             */
/*   Updated: 2022/06/23 21:25:22 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/libft.h"

void	init(t_param *param)
{
	param->game = (t_game *)malloc(sizeof(t_game));
	if (!(param->game))
		error_handler("Game Malloc Failed");
	param->game->collection = 0;
	param->game->entrance = 0;
	param->game->player = 0;
	param->game->move_count = 0;
	param->game->is_possible_exit = 0;
	param->game->is_done = 0;
	param->game->map_height = 0;
	param->game->map_width = 0;
}

void	argument_checker(int argc, char *argv)
{
	char	*map_path;

	if (argc != 2)
		error_handler("Please check your arguments");
	map_path = ft_strrchr(argv, '.');
	if ((map_path[0] != '.' || map_path[1] != 'b' || map_path[2] != 'e'
			|| map_path[3] != 'r' || map_path[4] != '\0'))
		error_handler("Please check your filename");
}
