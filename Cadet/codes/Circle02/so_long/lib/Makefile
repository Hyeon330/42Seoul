CFLAGS	= -Wall -Wextra -Werror
INC		= -Iheader

NAME	= libft.a

SRC		= ft_printf ft_take_info ft_checkers ft_field_counters \
		ft_arg_counters ft_input ft_puters \
		ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
		ft_strlen ft_toupper ft_tolower ft_strchr ft_strrchr \
		ft_strncmp ft_memchr ft_memset ft_memcmp ft_strnstr \
		ft_bzero ft_memcpy ft_memmove ft_strlcat ft_strlcpy \
		ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
		ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
		ft_putnbr_base ft_putunbr \
		get_next_line get_next_line_utils
OBJ		= $(SRC:.c=.o)

SRC_DIR	= src/
OBJ_DIR	= obj/

SRCS	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(OBJ)))


all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
