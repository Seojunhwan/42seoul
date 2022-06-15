# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 17:10:46 by junseo            #+#    #+#              #
#    Updated: 2022/06/15 14:14:27 by junseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

BONUS_PATH = ./bonus

SRCS = client.c \
		send_utils.c \
		utils.c \
		utils2.c \

BONUS_SRCS = ${BONUS_PATH}/client_bonus.c \
		${BONUS_PATH}/send_utils_bonus.c \
		${BONUS_PATH}/utils_bonus.c \
		${BONUS_PATH}/utils2_bonus.c \

OBJS_CLIENT = ${SRCS:.c=.o}
OBJS_CLIENT_BONUS = ${BONUS_SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

ifdef BONUS
	OBJECTS = $(OBJS_CLIENT_BONUS)
	HEADER_PATH = ./bonus
else
	OBJECTS = $(OBJS_CLIENT)
	HEADER_PATH = ./
endif

all: ${CLIENT}

${CLIENT}: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${CLIENT} -I ${HEADER_PATH}

bonus: 
	make BONUS=1 all

clean:
	${RM} ${OBJS_CLIENT} ${OBJS_CLIENT_BONUS}

fclean: clean
	${RM} ${CLIENT}

re: 
	make fclean
	make all

.PHONY: clean fclean re all bonus
