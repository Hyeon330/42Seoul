/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:05:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/24 16:27:55 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_args {
	char	**av;
	char	**env;
	int		ac;
	int		here_doc;
}	t_args;

// set_first_in_bonus.c
void	set_first_in(t_args args);

// child_proc_bonus.c
void	child_proc(int *fd, t_args args, int i);

// fd_ctrl_bonus.c
void	in_out(char *filename, int INOUT, int here_doc);
void	change_out(t_args args, int i, int *fd);

// sq_split_bonus.c
char	**sq_split(char const *s);

// error_bonus.c
void	ft_error(char *msg);
void	ft_perror(char *msg);

// libft.a
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif