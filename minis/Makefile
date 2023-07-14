NAME	= minishell

CFLAGS	= -Wall -Wextra -Werror

MAKE_INC_DIR	= include/
MAKE_INC		= minishell
MAKE_HEADERS	= $(addprefix $(MAKE_INC_DIR), $(addsuffix .h, $(MAKE_INC)))

INC_DIR	= $(MAKE_INC_DIR) $(HOME)/.brew/opt/readline/include lib/header
INC		= $(addprefix -I, $(INC_DIR))

READLINE	= -L$(HOME)/.brew/opt/readline/lib -lreadline

ENV_DIR		=	env/

PARSE_DIR	=	parse/

EXEC_DIR	=	exec/
EXEC_BUILTIN_DIR	=	$(EXEC_DIR)builtin/

ENV_FILES	=	insert remove search util_1 util_2 error

PARSE_FILES	=	

EXEC_FILES	=	exec child fd_ctrl util error
EXEC_BUILTIN_FILES	=	builtin echo cd pwd export unset env exit

FILES	=	main std_ioe clear \
			$(addprefix $(ENV_DIR), $(ENV_FILES)) \
			$(addprefix $(PARSE_DIR), $(PARSE_FILES)) \
			$(addprefix $(EXEC_DIR), $(EXEC_FILES)) \
			$(addprefix $(EXEC_BUILTIN_DIR), $(EXEC_BUILTIN_FILES))

OBJ_DIR	= obj/
SRC_DIR	= src/

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

LIB_DIR	= lib/
LIB		= $(LIB_DIR)libft.a

all: $(OBJ_DIR) $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(READLINE) $(OBJS) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MAKE_HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR) \
	$(OBJ_DIR)$(ENV_DIR) \
	$(OBJ_DIR)$(PARSE_DIR) \
	$(OBJ_DIR)$(EXEC_DIR) \
	$(OBJ_DIR)$(BUILTIN_DIR)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(RM)r $(OBJ_DIR)
	$(MAKE) fclean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
