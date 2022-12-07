/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:31:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/07 20:45:19 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// delete 
# include <stdio.h>

typedef struct s_strs {
	struct s_strs	*next;
	int				fd;
	int				buf_i;
	char			buf[BUFFER_SIZE];
}	t_strs;

char	*get_next_line(int fd);

#endif
