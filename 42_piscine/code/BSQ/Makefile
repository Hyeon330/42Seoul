CC = gcc
NAME = bsq
SRCS = bsq.c main.c size.c fill.c make_malloc.c map_check.c get_real_info.c
OBJS = $(SRCS:.c=.o)
INC = includes
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $@ -I $(INC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
