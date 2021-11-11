CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

SRCDIR = srcs
INC = libft.h

NAME = libft.a
SOURCES = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -I $(INC)

$(NAME): $(OBJECTS)
	ar crs $@ $(OBJECTS)

.PHONY: clean fclean all re bonus

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
