NAME = do-op

SRCS = main.c operator.c helper.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ -I ./ 
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean re
