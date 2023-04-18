NAME	= philo

CFLAGS	= -Wall -Wextra -Werror
INC		= -Iheader

SRC		= main

OBJ_DIR	= obj/
SRC_DIR	= src/

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIB) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	$(RM)r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus clean fclean re