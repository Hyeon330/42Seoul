NAME		=	ex00

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
INC 		=	-Iincludes

HEADERS 	=	$(wildcard includes/*.hpp)
SRC_DIRS 	=	srcs $(wildcard srcs/*)
SRCS 		=	$(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.cpp))
OBJS 		=	$(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re