# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 17:10:46 by junseo            #+#    #+#              #
#    Updated: 2022/06/15 14:02:23 by junseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

BONUS_PATH = ./bonus

SRCS = server.c \
		utils.c \
		utils2.c \
		utils3.c \
		receive_utils.c

BONUS_SRCS = ${BONUS_PATH}/server_bonus.c \
		${BONUS_PATH}/utils_bonus.c \
		${BONUS_PATH}/utils2_bonus.c \
		${BONUS_PATH}/utils3_bonus.c \
		${BONUS_PATH}/receive_utils_bonus.c

OBJS_SERVER = ${SRCS:.c=.o}
OBJS_SERVER_BONUS = ${BONUS_SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

ifdef BONUS
	OBJECTS = $(OBJS_SERVER_BONUS)
	HEADER_PATH = ./bonus
else
	OBJECTS = $(OBJS_SERVER)
	HEADER_PATH = ./
endif

all: ${SERVER}

${SERVER}: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${SERVER} -I ${HEADER_PATH}

bonus: 
	make BONUS=1 all

clean:
	${RM} ${OBJS_SERVER} ${OBJS_SERVER_BONUS}

fclean: clean
	${RM} ${SERVER}

re: 
	make fclean
	make all

.PHONY: clean fclean re all bonus
