/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:39:03 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/01 11:54:58 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <dirent.h>
# include <signal.h>
# include <stdbool.h>
//# include <termios.h>
# include <sys/stat.h>
# include "libft.h"
# include "readline/readline.h"
# include "readline/history.h"

# define PROMPT "\033[95mMiniShell$ \033[39m"
# define STDIN_BACK 3
# define STDOUT_BACK 4
# define STDERR_BACK 5

enum e_redir_type {
	IN_REDIR = 1,
	OUT_REDIR = 2,
	APPEND = 4,
	HEREDOC = 8
};

enum e_builtin {
	ECHO = 1,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	NONE
};

enum e_env_err {
	ENV_DYNAMIC = 0
};

enum e_exec_err_type {
	E_COMMON = 0,
	E_FILE = 32,
	E_CRITICAL = 64
};

enum e_exec_err {
	EXEC_DYNAMIC = E_COMMON,
	EXEC_CNF,
	EXEC_ISDIR = E_FILE,
	EXEC_PERM_DNI,
	EXEC_PIPE = E_CRITICAL,
	EXEC_OPEN,
	EXEC_FORK
};

typedef struct s_node_env {
	struct s_node_env	*left;
	struct s_node_env	*right;
	char				*key;
	char				*val;
}	t_node_env;

typedef struct s_env {
	t_node_env	*root;
	int			size;
}	t_env;

typedef struct s_redir {
	struct s_redir	*next;
	char			*file;
	int				type;
}	t_redir;

typedef struct s_cmd {
	struct s_cmd	*next;
	t_redir			*red;
	char			**av;
	int				ac;
}	t_cmd;

typedef struct s_token {
	t_cmd	*cmd;
	int		size;
}	t_token;

typedef struct s_vars {
	t_env	env;
	t_token	token;
	int		exit_code;
}	t_vars;

// std_ioe.c
void	std_ioe_backup(void);
void	std_ioe_back(void);
// clear.c
void	clear_token(t_token *token);
void	clear_ppc(char ***ppc);

// env
// util_1.c
void	set_env(t_env *env, char **p_env);
void	print_env(t_node_env *node, void (*visit)(t_node_env *), int builtin_no);
void	clear_env(t_node_env *node);
// util_2.c
char	**get_env(t_env *env);
// insert.c
void	insert_env(t_env *env, char *key, char *val);
// remove.c
void	remove_env(t_env *env, char *key);
// search.c
char	*search_env(t_node_env *node, char *key);
// error.c
int		ft_env_error(int e_no);

// exec
// exec.c
void	exec(t_vars *vars);
// child.c
int		child_proc(t_vars *vars, t_cmd *cmd, int *fd, int builtin_no);
// execute.c
void	execute(t_vars *vars, t_cmd *cmd);
// fd_ctrl.c
void	pipex(int *fd, int INOUT);
int		fd_ctrl(t_cmd *cmd, int *fd);
// util.c
int		isdir(char	*path);
char	**get_pair(char *str);
char	*strjoin_between_char(char *str1, char *str2, char c);
// error.c
int		ft_exec_err(int e_no, char *cmd, char *str);

// exec/builtin
// builtin.c
int		isbuiltin(t_cmd *cmd);
int		builtin(t_vars *vars, t_cmd *cmd, int builtin_no);
// echo.c
int		echo(t_cmd *cmd);
// cd.c
int		cd(t_cmd *cmd, t_env *env);
// pwd.c
int		pwd(t_node_env *root);
// export.c
int		export(t_cmd *cmd, t_env *env);
// unset.c
int		unset(t_cmd *cmd, t_env *env);
// env.c
int		env(t_node_env *env);
// exit.c
int		exit_clear(t_vars *vars, t_cmd *cmd);

void	rl_replace_line(const char *, int);

//parse

//error.c
void	error(char *msg);
int		error_parse(int error, t_vars *vars);

//free_parse.c
void	free_two_dimen(char	**str);

//heredoc.c
void	write_heredoc(int fd, char *limiter);
char	*get_heredoc_filename(void);
char	*heredoc_join_path(char *file_name);
char	*heredoc_main(char *limiter);

//parse_init.c
t_cmd	*init_cmd(void);
t_redir	*init_redir(void);

//parse_utils.c
int		get_token_size(char *str);
int		check_redirection(char *str);
int		check_only_whitespace(char *str);

//parse.c
int	parse(t_vars *vars, char *str);

//replace_utils.c
int		count_replace(char *str);
int		check_wave(char *str, int i);
int		check_env(char *str, int i);

//replace.c
char	*replace_wave(char *str, t_vars vars, int i);
char	*replace_env(char *str, t_vars vars, int i);
char	*replace_exit_code(char *str, t_vars vars, int i);
char	*replace_character(char	*str, t_vars vars, int cnt);

//signal.c
void	handler(int signum);
void	signal_set(void);

//split_token_count.c
int		count_redir(char *s, int i);
int		count_quote(char *s, int i, t_vars *vars);
int		count_env(char *s);
int		count_token(char *s, char c, t_vars *vars);

//split_token.c
void	free_splited_token(char **s);
char	*split_quote(char *s);
char	**do_split_token(char *s, char **splited, char c, t_vars vars);
char	**split_token_main(char *str, t_vars *vars);

//split_token2.c
char	*when_redir(char **s);
char	*when_quote(char	**s);
char	*when_charset(char **s, char c, t_vars vars);

//syntax.c
int		syntax_redirection(char **splited, int i, t_vars *vars);
int		syntax_word(char **splited, int i, t_vars *vars);
int		syntax_check(char **splited, int order, t_vars *vars);

//tokenize.c
t_redir	*tokenize_redir(t_cmd *cmd, char *redir, char *file);
char	**tokenize_av(int cnt, char **splited);
t_cmd	*tokenize(t_cmd *cmd, char **splited);

#endif