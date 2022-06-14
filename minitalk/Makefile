# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/11 17:10:46 by junseo            #+#    #+#              #
#    Updated: 2022/06/14 03:04:56 by junseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT 	= libft/libft.a
SERVER = server
CLIENT = client

SRCS_SERVER = server.c \
								utils.c \
								utils2.c \


SRCS_CLIENT = client.c \
								utils.c \
								utils2.c \


OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

all: ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SERVER}
	@${CC} ${OBJS_SERVER} ${CFLAGS} -o ${SERVER} -I ./

${CLIENT}: ${OBJS_CLIENT}
	@${CC} ${OBJS_CLIENT} ${CFLAGS} -o ${CLIENT} -I ./

# clean:
# 	@${RM} ${OBJS_SERVER}
# 	@${RM} ${OBJS_CLIENT}

# fclean: clean
# 	@${RM} ${SERVER}
# 	@${RM} ${CLIENT}

re: 
	make fclean
	make all

.PHONY: clean fclean re all
