CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memset.c ft_memcmp.c ft_strnstr.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcat.c ft_strlcpy.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BONUS = ft_lstnew.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(OBJS)
	rm -rf $(NAME) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	rm -rf $(NAME)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#$(NAME): $(OBJS)
#	ar rc $@ $(OBJS)

clean:
	rm -rf ./*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
