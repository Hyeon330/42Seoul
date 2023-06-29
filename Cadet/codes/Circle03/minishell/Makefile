NAME	= minishell

CFLAGS	= -Wall -Wextra -Werror

HEADER	= includes readline/include lib/header
INC		= $(addprefix -I, $(HEADER))

BUILTIN_DIR		= builtin/
BUILTIN_FILES	= echo cd pwd export unset env exit

FILES	=	main builtin error exec execution fd_ctrl redirection signal_handler tree1 tree2 tree_order \
			$(addprefix $(BUILTIN_DIR), $(BUILTIN_FILES)) \
			x_build_cmd_argv x_build_cmd_argv2 x_build_nodes x_free_utils \
			x_lstcmd x_lstcmd2 x_ms_str x_ms_str2 x_ms_utils \
			x_parse x_pre_parse_env x_pre_parse x_split_pipe x_split_pipe2 \
			x_split_tok x_split_tok2 x_split_tok3\

OBJ_DIR	= obj/
SRC_DIR	= src/

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

LIB_DIR	= lib/
LIB		= $(LIB_DIR)libft.a

READLINE	= -Lreadline/lib -lreadline

all: $(OBJ_DIR) $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(READLINE) $(OBJS) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c header/minishell.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)
	mkdir $(OBJ_DIR)$(BUILTIN_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(RM)r $(OBJ_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) fclean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
