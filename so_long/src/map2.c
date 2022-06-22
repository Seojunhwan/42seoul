/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:43:29 by junseo            #+#    #+#             */
/*   Updated: 2022/06/22 22:42:17 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	open_map(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_handler("Can not open map file");
	return (fd);
}
