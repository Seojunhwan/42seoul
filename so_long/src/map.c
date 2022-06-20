/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:33:41 by junseo            #+#    #+#             */
/*   Updated: 2022/06/20 22:01:30 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(char *path, t_game *game)
{
	char	*line;
	int		fd;

	fd = open_map(path);
	line = get_next_line(fd);
	game->map_height = 0;
	game->map_width = ft_strlen(line) - 1;
	// game->map = 
	// while (line)
	// {
	// }
}

int	open_map(const char *path)
{
	int	fd;

		fd = open(path, O_RDONLY);
	if (fd == -1)
		error_handler(ERROR_MAP_PARSING);
	return (fd);
}
