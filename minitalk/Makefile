# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 17:10:46 by junseo            #+#    #+#              #
#    Updated: 2022/06/15 14:14:08 by junseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minitalk
SERVER_DIR		=	./server/
CLIENT_DIR		=	./client/

all:
	make -C ${SERVER_DIR} all
	make -C ${CLIENT_DIR} all

bonus:
	make -C ${SERVER_DIR} bonus
	make -C ${CLIENT_DIR} bonus

clean:
	make -C ${SERVER_DIR} clean
	make -C ${CLIENT_DIR} clean

fclean:
	make -C ${SERVER_DIR} fclean
	make -C ${CLIENT_DIR} fclean

re: 
	make -C ${SERVER_DIR} re
	make -C ${CLIENT_DIR} re

.PHONY: clean fclean re all bonus
