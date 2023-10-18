# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 23:12:02 by hoseoson          #+#    #+#              #
#    Updated: 2023/10/06 00:22:54 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
LIB			= 	./libft/libft.a libmlx.dylib
FRAMEWORK	=	-framework OpenGL -framework AppKit
INCLUDES 	=	-Iincludes -Ilibft/header -Iminilibx_mms

SOURCES		=	srcs/main.c \
				srcs/exec/move.c srcs/exec/raycasting.c srcs/exec/rotate.c \
				srcs/exec/run.c srcs/exec/util.c \
				srcs/parse/checker.c srcs/parse/error.c srcs/parse/parse.c \
				srcs/parse/setter_id.c srcs/parse/setter_map.c srcs/parse/util.c
OBJECTS 	=	$(SOURCES:.c=.o)
HEADERS		=	includes/cub3d.h

all : $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C libft
	$(MAKE) -C minilibx_mms
	mv ./minilibx_mms/libmlx.dylib ./
	$(CC) $(CFLAGS) $(LIB) $(INCLUDES) -o $@ $^

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean : 
	$(MAKE) -C libft $@
	$(MAKE) -C minilibx_mms $@
	$(RM) $(OBJECTS)

fclean : clean
	$(MAKE) -C libft $@
	$(RM) libmlx.dylib
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
