CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

NAME	= push_swap
BONUS	= checker

SRC	= main.c push_swap.c push.c deque.c operations.c sort.c set_deque.c run.c greedy1.c greedy2.c
OBJ	= $(SRC:.c=.o)

SRCS	= $(addprefix $(SRC_DIR), $(SRC))
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

SRC_BONUS = main_bonus.c deque_bonus.c operations_bonus.c set_deque_bonus.c run_bonus.c checker_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

SRCS_BONUS = $(addprefix $(SRC_DIR), $(SRC_BONUS))
OBJS_BONUS = $(addprefix $(OBJ_DIR), $(OBJ_BONUS))

SRC_DIR	= src/
OBJ_DIR	= obj/

LIB_DIR	= lib/
LIB		= $(LIB_DIR)libft.a

all: $(OBJ_DIR) $(NAME)

bonus: $(OBJ_DIR) $(BONUS)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(BONUS): $(OBJS_BONUS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) fclean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re:
	make fclean
	make all

.PHONY: bonus clean fclean re
