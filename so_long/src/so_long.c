/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:36:09 by junseo            #+#    #+#             */
/*   Updated: 2022/06/20 21:07:17 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_param	*param;

	if (argc != 2)
		error_handler(ERROR_WRONG_ARGC);
	param = (t_param *)malloc(sizeof(t_param));
	if (!param)
		error_handler(ERROR_MALLOC);
	return (0);
}

	// arguments check
	// struct initialize