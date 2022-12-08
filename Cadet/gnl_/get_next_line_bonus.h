/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:35:18 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/08 23:37:52 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# define FREE(ptr) if (ptr) { free(ptr); ptr = NULL; }

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//delete
# include <stdio.h>

typedef struct s_buflst {
	struct s_buflst	*next;
	ssize_t			read_size;
	ssize_t			buf_i;
	char			*buf;
	int				fd;
}	t_buflst;

typedef struct s_strlst {
	struct s_strlst	*next;
	ssize_t			size;
	char			str[BUFFER_SIZE];
}	t_strlst;

// get_next_line_bonus.c
char	get_next_line(int fd);

// get_next_line_utils_bonus.c
void	ft_strjoin(char **dst, char *src, ssize_t dst_len, ssize_t src_len);

#endif
