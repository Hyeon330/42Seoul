/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:05:16 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/25 16:30:33 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_args {
	char	**av;
	char	**env;
	int		ac;
}	t_args;

// child_proc.c
void	child_proc(int *fd, t_args args, int i);

// fd_ctrl.c
void	in_out(char *filename, int INOUT);
void	change_out(t_args args, int i, int *fd);

// sq_split.c
char	**sq_split(char const *s);

// error.c
void	ft_error(char *msg);
void	ft_perror(char *msg);

// libft.a
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif