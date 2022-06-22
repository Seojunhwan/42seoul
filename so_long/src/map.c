/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:33:41 by junseo            #+#    #+#             */
/*   Updated: 2022/06/22 22:48:56 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/includes/get_next_line.h"

void	parse_map(t_game *game, char *path)
{
	char	*line;
	char	*buf;
	char	*temp;
	int		fd;

	fd = open_map(path);
	buf = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (*line == '\n')
			error_handler("Found too many new line");
		temp = ft_strjoin(buf, line);
		free(buf);
		free(line);
		if (!temp)
			error_handler("Map parsing error");
		buf = temp;
		line = get_next_line(fd);
	}
	game->map = ft_split(buf, '\n');
	free(buf);
	if (!(game->map[0]))
		error_handler("Map is empty");
}

void	tile_handler(t_game *game, t_tile tile, int r_idx, int c_idx)
{
	if (tile == TILE_COLLECTION)
		game->collection++;
	else if (tile == TILE_PLAYER)
	{
		game->player++;
		game->pos.col = c_idx;
		game->pos.row = r_idx;
	}
	else if (tile == TILE_ENTRANCE)
		game->entrance++;
	else if (tile != TILE_LAND && tile != TILE_WALL)
		error_handler("Please check your map file : TileCode");
}

void	column_checker(t_game *game, int r_idx, int is_wall)
{
	int	c_idx;

	c_idx = 0;
	if (is_wall)
	{
		while (game->map[r_idx][c_idx] != '\0')
			if (game->map[r_idx][c_idx++] != TILE_WALL)
				error_handler("Please check your map file : Wall");
	}
	else
	{
		while (game->map[r_idx][c_idx] != '\0')
		{
			if (c_idx == 0 || c_idx == game->map_width - 1)
			{
				if (game->map[r_idx][c_idx] != TILE_WALL)
					error_handler("Please check your map file : Wall");
			}
			else
				tile_handler(game, game->map[r_idx][c_idx], r_idx, c_idx);
		c_idx++;
		}
	}
	if (c_idx != game->map_width)
		error_handler("Map is not rectangle");
}

void	row_checker(t_game *game)
{
	int	row_index;
	int	i;

	i = 0;
	row_index = 0;
	while (game->map[i] != NULL)
		i++;
	while (row_index < (game->map_height))
	{
		if (row_index == 0 || row_index == (game->map_height) - 1)
			column_checker(game, row_index, 1);
		else
			column_checker(game, row_index, 0);
		row_index++;
	}
}

void	check_map(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(game->map[0]);
	while ((game->map[i++]) != NULL)
		;
	game->map_height = i - 1;
	row_checker(game);
	if (!(game->collection > 0 && game->entrance > 0 && game->player == 1))
		error_handler("Minimum condition was not met");
}
