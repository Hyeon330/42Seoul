/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:39:03 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/19 11:02:22 by hyeonsul         ###   ########.fr       */
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

# define PATH_LEN 1024

enum e_err {
	DYNAMIC = 0,
	CHDIR_PATH,
	CHDIR_ARG,
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

typedef struct s_env {
	struct s_env	*left;
	struct s_env	*right;
	char			*key;
	char			*val;
}	t_env;

// exec.c
void	exec(t_cmd **cmds, int cmd_num, char **env);

// builtin.c
void	builtin(int builtin_no, t_cmd *cmd, char **env);

// fd_ctrl.c
void	fd_ctrl(t_cmd *cmd, int pipe_chk, int *fd);

// redirection.c
void	in_redir(t_cmd *cmd);
void	out_redir(t_cmd *cmd);

// tree.c
void	insert(t_env **root, char *key, char *val);
char	*search(t_env *node, char *key);

// tree_order.c
void	inorder(t_env *node);

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
void    *ft_calloc(size_t count, size_t size);

#endif