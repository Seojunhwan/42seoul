# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 17:10:46 by junseo            #+#    #+#              #
#    Updated: 2022/06/14 20:27:02 by junseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SRCS = client.c \
		send_utils.c \
		utils.c \

OBJS_CLIENT = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${CLIENT}

${CLIENT}: ${OBJS_CLIENT}
	@${CC} ${OBJS_CLIENT} ${CFLAGS} -o ${CLIENT} -I ./

clean:
	@${RM} ${OBJS_CLIENT}

fclean: clean
	@${RM} ${CLIENT}

re: 
	make fclean
	make all

.PHONY: clean fclean re all
