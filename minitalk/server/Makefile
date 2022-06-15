# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 17:10:46 by junseo            #+#    #+#              #
#    Updated: 2022/06/15 13:17:26 by junseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

SRCS = server.c \
		utils.c \
		utils2.c \
		utils3.c \
		receive_utils.c

OBJS_SERVER = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: ${SERVER}

${SERVER}: ${OBJS_SERVER}
	@${CC} ${OBJS_SERVER} ${CFLAGS} -o ${SERVER} -I ./

clean:
	@${RM} ${OBJS_SERVER}

fclean: clean
	@${RM} ${SERVER}

re: 
	make fclean
	make all

.PHONY: clean fclean re all
