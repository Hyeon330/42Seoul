/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:31:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/06 20:18:43 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

// delete 
# include <stdio.h>
# define BUFF_SIZE 42

typedef struct s_strs {
	struct s_strs	*next;
	int				fd;
	int				buf_i;
	char			buf[BUFF_SIZE];
}	t_strs;

char	*get_next_line(int fd);

#endif
