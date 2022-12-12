/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:35:18 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/12 18:22:13 by hyeonsul         ###   ########.fr       */
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

typedef struct s_buflst {
	struct s_buflst	*next;
	ssize_t			read_size;
	ssize_t			buf_i;
	char			*buf;
	int				fd;
}	t_buflst;

// get_next_line_bonus.c
char		*get_next_line(int fd);

// get_next_line_utils_bonus.c
void		ft_strjoin(char **dst, char *src, ssize_t dst_len, ssize_t src_len);
t_buflst	*isfd(t_buflst *buflst, int fd);
t_buflst	*lstnew(int fd);
void		lstadd_back(t_buflst **lst, t_buflst *new);
void		lstdelone(t_buflst **lst, t_buflst *lst_copy, int fd);

#endif
