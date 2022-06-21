/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:03:04 by junseo            #+#    #+#             */
/*   Updated: 2022/06/21 19:32:59 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_param *param)
{
	param->game = (t_game *)malloc(sizeof(t_game));
	if (!(param->game))
		error_handler(ERROR_MALLOC);
	param->game->collection = 0;
	param->game->entrance = 0;
	param->game->player = 0;
	param->game->move_count = 0;
	param->game->is_exist_collection = 0;
	param->game->is_exist_entrance = 0;
	param->game->is_exist_player = 0;
	param->game->is_possible_exit = 0;
	param->game->map = (char **)malloc(sizeof(char *) + 1);
	param->game->map[1] = NULL;
	if (!(param->game->map))
		error_handler(ERROR_MALLOC);
	param->game->map_height = 0;
	param->game->map_width = 0;
}

void	argument_checker(int argc, char *argv)
{
	int		file_length;
	char	*temp;

	if (argc != 2)
		error_handler(ERROR_WRONG_ARGUMENTS);
	temp = argv;
	temp = ft_strrchr(argv, '.');
	if ((temp[0] != '.' || temp[1] != 'b' || temp[2] != 'e' || temp[3] != 'r'
			|| temp[4] != '\0'))
		error_handler(ERROR_WRONG_ARGUMENTS);
}
