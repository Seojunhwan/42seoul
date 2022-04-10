LIBFT 	= libft/libft.a

NAME	= libftprintf.a

SRCS	= 	ft_printf.c \
			ft_hex_utils.c \
			ft_pointer_utils.c \
			ft_decimal_utils.c \
			ft_str_utils.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc
AR		= ar crs
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp $(LIBFT) ./$(NAME)
			$(AR) $(NAME) $(OBJS)

clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all, bonus, clean, fclean, re