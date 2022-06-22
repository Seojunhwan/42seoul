# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:10:46 by junseo            #+#    #+#              #
#    Updated: 2022/06/22 22:53:34 by junseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

LIBFTGNL_DIR	=	./libft
MLX_DIR			=	./mlx

SRCS			=	src/init.c	\
					src/map.c	\
					src/map2.c	\
					src/move.c	\
					src/paint_game.c	\
					src/so_long.c	\
					src/utils.c	

OBJS			=	$(SRCS:.c=.o)
CLIB			=	-L$(MLX_DIR) -lmlx -L$(LIBFTGNL_DIR) -lftgnl \
					-framework OpenGL -framework AppKit

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) -C $(LIBFTGNL_DIR)
				$(MAKE) -C $(MLX_DIR)
				$(CC) $(CFLAGS) $(CLIB) $(OBJS) -o $(NAME)

clean:
				$(MAKE) clean -C $(LIBFTGNL_DIR)
				$(MAKE) clean -C $(MLX_DIR)
				$(RM) $(OBJS)

fclean: 		clean
				$(MAKE) fclean -C $(LIBFTGNL_DIR)
				$(RM) $(NAME)

re: 
	make fclean
	make all

.PHONY: clean fclean re all
