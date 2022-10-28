CC = gcc
CFALGS = -Wall -Wextra -Werror -c
SRCDIR = srcs
HEADER = includes

NAME = libft.a
SRCS = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strcmp.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_swap.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFALGS) $< -o $@ -I $(HEADER)

$(NAME): $(OBJECTS)
	ar rc $@ $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
