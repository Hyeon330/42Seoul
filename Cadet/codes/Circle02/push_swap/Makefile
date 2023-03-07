CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS = checker

SRCS = main.c push_swap.c push.c deque.c operations.c sort.c set_deque.c run.c greedy1.c greedy2.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = main_bonus.c deque_bonus.c operations_bonus.c set_deque_bonus.c run_bonus.c checker_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIB = -Llib -lftprintf -lft
LIB_BONUS = -Llib_bonus -lgnl -lftprintf -lft

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) $(LIB_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re:
	make fclean
	make all

.PHONY: bonus clean fclean re
