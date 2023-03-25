NAME	= pipex

CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

SRC		= main.c child_proc.c fd_ctrl.c sq_split.c error.c

SRC_BONUS	= 	main_bonus.c set_first_in_bonus.c child_proc_bonus.c \
				fd_ctrl_bonus.c sq_split_bonus.c error_bonus.c

OBJ_DIR		= obj/
OBJ_BONUS_DIR	= obj_bonus/
ifeq ($(filter $(MAKECMDGOALS), bonus), bonus)
SRC_DIR		= src_bonus/
SRCS        = $(addprefix $(SRC_DIR), $(SRC_BONUS))
OBJ         = $(SRC_BONUS:.c=.o)
OBJS        = $(addprefix $(OBJ_BONUS_DIR), $(OBJ))
else
SRC_DIR		= src/
SRCS        = $(addprefix $(SRC_DIR), $(SRC))
OBJ         = $(SRC:.c=.o)
OBJS        = $(addprefix $(OBJ_DIR), $(OBJ))
endif

LIB_DIR	= lib/
LIB		= $(LIB_DIR)libft.a

all: $(OBJ_DIR) $(NAME)
	$(RM) $(OBJ_BONUS_DIR)

bonus: $(OBJ_BONUS_DIR) $(NAME)
	$(RM) $(OBJ_DIR)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	mkdir $(OBJ_BONUS_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(RM) $(OBJ_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) fclean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus clean fclean re