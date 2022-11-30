CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c ./libft/ft_putchar_fd.c ./libft/ft_putnbr_base.c ./libft/ft_putnbr_fd.c ./libft/ft_putunbr.c ./libft/ft_putstr_fd.c ./libft/ft_strlen.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_printf_bonus.c ft_take_info_bonus.c ft_checkers_bonus.c ft_field_counters_bonus.c ft_arg_counters_bonus.c ft_input_bonus.c ft_puters_bonus.c libft/ft_strlen.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

HEADER = ./libft

all : $(NAME)

$(NAME): $(OBJS)
	$(RM) all bonus $(NAME)
	ar rc $(NAME) $(OBJS)
	touch all

bonus: $(OBJS_BONUS)
	$(RM) all bonus $(NAME)
	ar rc $(NAME) $(OBJS_BONUS)
	touch bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) all bonus

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: clean fclean re
