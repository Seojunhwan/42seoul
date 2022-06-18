/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:33:48 by junseo            #+#    #+#             */
/*   Updated: 2022/06/18 16:45:02 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
// # include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define IMG_SIZE			64
# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D 				2
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	send_end_signal(void);
void	send_signal(void);
void	send_handshake(void);
void	ft_verify_bit(char c, int bit);
void	ft_putstr_fd(char *s, int fd);

#endif
