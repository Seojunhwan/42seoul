/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:33:48 by junseo            #+#    #+#             */
/*   Updated: 2022/06/20 21:57:21 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../get_next_line.h"
// # include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define IMG_SIZE			64
# define TRUE = 1;
# define FALSE = 0;

typedef struct s_position
{
	int	row;
	int	col;
}	t_position;

typedef struct s_game
{
	char		*map;
	int			map_width;
	int			map_height;
	int			collection;
	int			is_open_entrance;
	int			move_count;
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
	KEW_A = 0,
	KEY_D = 2,
	KEY_ESC = 53,
	X_EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_EXIT = 17
}	t_key_code;

typedef enum e_list_of_error
{
	ERROR_MALLOC,
	ERROR_MAP_PARSING,
	ERROR_WRONG_ARGC,
	ERROR_WRONG_MAP_FILE,
}	t_error_code;

void	error_handler(t_error_code error);

#endif
