/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:15:51 by junseo            #+#    #+#             */
/*   Updated: 2022/06/20 21:02:07 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler(t_error_code error)
{
	if (error == ERROR_WRONG_ARGC)
	{
		printf("CHECK THE ARGUMENTS");
		exit(1);
	}
	else if (error == ERROR_MAP_PARSING)
	{
		printf("CHECK THE ARGUMENTS");
		exit(1);
	}
	else if (error == ERROR_MALLOC)
	{
		printf("AN ERROR OCCURRED WHILE MALLOC");
		exit(1);
	}
	else if (error == ERROR_WRONG_MAP_FILE)
	{
		printf("CHECK THE MAP FILE");
		exit(1);
	}
}
