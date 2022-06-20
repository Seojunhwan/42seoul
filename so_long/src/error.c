/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:15:51 by junseo            #+#    #+#             */
/*   Updated: 2022/06/21 05:08:09 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler(t_error_code error)
{
	printf("ERROR\n");
	if (error == ERROR_WRONG_ARGUMENTS)
		printf("CHECK THE ARGUMENTS");
	else if (error == ERROR_MAP_PARSING)
		printf("CHECK THE MAP FILE");
	else if (error == ERROR_MALLOC)
		printf("AN ERROR OCCURRED WHILE MALLOC");
	else if (error == ERROR_WRONG_MAP_FILE)
		printf("CHECK THE MAP FILE");

	exit(1);
}

void	free_all(t_param *param)
{
	
}