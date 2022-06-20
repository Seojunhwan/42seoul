/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:33:41 by junseo            #+#    #+#             */
/*   Updated: 2022/06/21 05:05:34 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_game *game, char *path)
{
	char	*line;
	char	*buf;
	char	*temp;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_handler(ERROR_MAP_PARSING);
	buf = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (*line == '\n')
			error_handler(ERROR_MAP_PARSING);
		temp = ft_strjoin(buf, line);
		free(line);
		if (!temp)
			error_handler(ERROR_MAP_PARSING);
		free(buf);
		buf = temp;
		line = get_next_line(fd);
	}
	game->map = ft_split(buf, '\n');
	free(buf);
	if (!game->map)
		error_handler(ERROR_MAP_PARSING);
}

void	tile_handler(t_game *game, t_tile tile, int c_idx, int r_idx)
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
	else if (tile != TILE_BLANK && tile != TILE_WALL)
		error_handler(ERROR_MAP_PARSING);
}

void	row_checker(t_game *game, int c_idx, int is_wall)
{
	int	r_idx;

	r_idx = 0;
	if (is_wall)
	{
		while (game->map[c_idx][r_idx] != '\0')
			if (game->map[c_idx][r_idx++] != TILE_WALL)
				error_handler(ERROR_MAP_PARSING);
	}
	else
	{
		while (game->map[c_idx][r_idx] != '\0')
		{
			if (r_idx == 0 || r_idx == game->map_width - 1)
			{
				if (game->map[c_idx][r_idx] != TILE_WALL)
					error_handler(ERROR_MAP_PARSING);
			}
			else
				tile_handler(game, game->map[c_idx][r_idx], c_idx, r_idx);
		r_idx++;
		}
	}
	if (r_idx != game->map_width)
		error_handler(ERROR_MAP_PARSING);
}

void	column_checker(t_game *game)
{
	int	column_index;
	int	i;

	i = 0;
	column_index = 0;
	printf("\n%d %d\n", column_index, game->map_height);
	while (game->map[i] != NULL)
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	while (column_index < (game->map_height))
	{
		if (column_index == 0 || column_index == (game->map_height) - 1)
			row_checker(game, column_index, 1);
		else
			row_checker(game, column_index, 0);
		column_index++;
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
	column_checker(game);
	printf("collection : %d", game->collection);
	if (!(game->collection > 0 && game->entrance > 0 && game->player == 1))
		error_handler(ERROR_MAP_PARSING);
}

// 방금 읽었은거

// 2차원 배열
// [
// 	['a','a','a','a','a','a','a'],
// 	['b','b','b','b','b','b','b'],
// 	['c','c','c','c','c','c','c'],
// 	['d','d','d','d','d','d','d'],
//	 NULL
// ]

// i 2차원 배열 내부의 1차원 배열의 갯수
// 2차원 배열을 재할당하구
// 기존 2차원 배열 내부의 1차원 배열들의 주소를 붙여넣구
// 기존 2차원 배열은 free 해주고!
// 방금 들어온 1차원 배열의 주소를 마지막에 넣어주고
// 리턴하면 끝