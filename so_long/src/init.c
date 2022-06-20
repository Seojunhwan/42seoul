/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:03:04 by junseo            #+#    #+#             */
/*   Updated: 2022/06/20 21:53:24 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_param *param)
{
	param->game = (t_game *)malloc(sizeof(t_game));
	if (!(param->game))
		error_handler(ERROR_MALLOC);
	param->game->collection = 0;
	param->game->is_open_entrance = 0;
}

void	check_argument(char *argv)
{

}