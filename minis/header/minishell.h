/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:39:03 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/15 12:43:41 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <dirent.h>
# include <signal.h>

enum e_err {
	DYNAMIC = 0,
	CHDIR_PATH = 1,
	CHDIR_ARG = 2,
	SYSTEM = 32
};

enum e_builtin {
	ECHO = 1,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV
};

enum e_type {
	CMD = 1,
	IN_REDIR = 2,
	OUT_REDIR = 4,
	HERE_DOC = 8,
	APPEND = 16
};

typedef struct s_cmd {
	struct s_cmd	*next;
	char			*path;
	char			**av;
	int				ac;
	int				type;
}	t_cmd;

// exec.c
void	exec(t_cmd **cmds, int cmd_num, char **env);

// builtin.c
void	builtin(int builtin_no, t_cmd *cmd);

// fd_ctrl.c
void	fd_ctrl(t_cmd *cmd, int pipe_chk, int *fd);

// redirection.c
void	in_redir(t_cmd *cmd);
void	out_redir(t_cmd *cmd);

// error.c
void	ft_error(int e_no);

// libft.a
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);

#endif