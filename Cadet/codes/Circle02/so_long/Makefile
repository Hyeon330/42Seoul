NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

SRC		= main.c checker.c bfs.c queue.c free_two_ptr.c error.c
OBJ		= $(SRC:.c=.o)

OBJ_DIR	= obj/
SRC_DIR = src/

SRCS	= $(addprefix $(SRC_DIR), $(SRC))
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

LIB_DIR	= lib/
LIB		= $(LIB_DIR)libft.a

MLX_DIR	= mlx/

all: $(OBJ_DIR) $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) fclean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus clean fclean re