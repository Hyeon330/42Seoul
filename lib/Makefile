CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

NAME	= libft.a

SRC		= ft_printf.c ft_take_info.c ft_checkers.c ft_field_counters.c \
		ft_arg_counters.c ft_input.c ft_puters.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memset.c ft_memcmp.c ft_strnstr.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcat.c ft_strlcpy.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putnbr_base.c ft_putunbr.c \
		get_next_line.c get_next_line_utils.c
OBJ		= $(SRC:.c=.o)

SRC_DIR	= src/
OBJ_DIR	= obj/

SRCS	= $(addprefix $(SRC_DIR), $(SRC))
OBJS	= $(addprefix $(OBJ_DIR), $(OBJ))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
