CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

NAME	= pipex

SRC		= main.c child_proc.c fd_ctrl.c sq_split.c error.c

SRC_BONUS	= 	main_bonus.c set_first_in_bonus.c child_proc_bonus.c \
				fd_ctrl_bonus.c sq_split_bonus.c error_bonus.c

OBJ_DIR	= obj/
ifeq ($(MAKECMDGOALS), bonus)
SRC_DIR		= src_bonus/
SRCS        = $(addprefix $(SRC_DIR), $(SRC_BONUS))
OBJ         = $(SRC_BONUS:.c=.o)
else
SRC_DIR		= src/
SRCS        = $(addprefix $(SRC_DIR), $(SRC))
OBJ         = $(SRC:.c=.o)
endif
OBJS        = $(addprefix $(OBJ_DIR), $(OBJ))

LIB_DIR	= lib/
LIB		= $(LIB_DIR)libft.a

all: $(OBJ_DIR) $(NAME)

bonus: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

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
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: bonus clean fclean re