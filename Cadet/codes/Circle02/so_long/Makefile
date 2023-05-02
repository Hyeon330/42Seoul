NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror

HEADER	= header
INC		= -I$(HEADER)

SRC		= main setting viewer checker bfs queue error

OBJ_DIR	= obj/
SRC_DIR = src/

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

LIB_DIR	= lib/
LIB		= $(LIB_DIR)libft.a

MLX_DIR	= mlx/

all: $(OBJ_DIR) $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)/so_long.h
	$(CC) $(CFLAGS) $(INC) -Imlx -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR)
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM)r $(OBJ_DIR)
	$(MAKE) fclean -C $(LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
