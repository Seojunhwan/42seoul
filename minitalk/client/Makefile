# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 17:10:46 by junseo            #+#    #+#              #
#    Updated: 2022/06/15 13:17:20 by junseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SRCS = client.c \
		send_utils.c \
		utils.c \
		utils2.c \

OBJS_CLIENT = ${SRCS:.c=.o}
CC = cc
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
