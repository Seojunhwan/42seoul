/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:33:48 by junseo            #+#    #+#             */
/*   Updated: 2022/06/21 22:55:58 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
// # include "../libft/libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define IMG_SIZE	64
# define TRUE	1;
# define FALSE	0;

typedef struct s_position
{
	int	row;
	int	col;
}	t_position;

typedef struct s_game
{
	char		**map;
	int			map_width;
	int			map_height;
	int			collection;
	int			entrance;
	int			player;
	int			move_count;
	int			is_exist_entrance;
	int			is_exist_collection;
	int			is_exist_player;
	int			is_possible_exit;
	t_position	pos;
}	t_game;

typedef struct s_param
{
	void	*mlx;
	void	*win;
	t_game	*game;
}	t_param;

typedef enum e_list_of_key_code
{
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_ESC = 53,
	X_EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_EXIT = 17
}	t_key_code;

typedef enum e_list_of_error
{
	ERROR_MALLOC,
	ERROR_MAP_PARSING,
	ERROR_WRONG_ARGUMENTS,
	ERROR_WRONG_MAP_FILE,
}	t_error_code;

typedef enum e_list_of_tile
{
	TILE_LAND = '0',
	TILE_WALL = '1',
	TILE_COLLECTION = 'C',
	TILE_PLAYER = 'P',
	TILE_ENTRANCE = 'E'
}	t_tile;

void	error_handler(t_error_code error);
void	argument_checker(int argc, char *argv);
void	parse_map(t_game *game, char *map_path);
void	check_map(t_game *game);
char	*get_next_line(int fd);
char	**put_line_to_map(t_game *game, char *line);
void	init(t_param *param);
void	paint_game(t_param *param);
int		handle_key_down(int key_code, t_param *param);
int		handle_exit_game(t_param *param);
void	temp_paint(t_param *param);

#endif
