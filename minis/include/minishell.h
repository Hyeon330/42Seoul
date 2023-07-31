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

//check_readline.c
int		check_valid_redir(char *s);
int		check_valid_pipe(char *str);
int		check_valid_quote(char *str);
char	**check_readline(char *str);

//parse_error.c
int		error_parse(int error, t_vars *vars);
void	error(char *msg);

//parse_free.c
void	free_two_dimen(char	**str);

//parse_init.c
t_redir	*init_redir(void);
t_cmd	*init_cmd(void);

//parse_utils.c
int		check_redirection(char *str);
int		check_only_whitespace(char *str);
int		is_redir(char *str, int i);

//parse.c
int		parse(t_vars *vars, char *str);
void	do_parse(t_vars *vars, char **splited_pipe);

//remove_quote.c
int		check_quote(char *str);
char	*remove_quote(char *splited_token);
void	remove_quote_main(char **splited_token);

//replace_count.c
int		count_env_quote(char *str);
int		count_wave(char *s);
int		count_env(char *str);

//replace_free.c
void	free_replace_env(char *front, char *back, char *env);
void	free_replace_wave(char *temp, char *home, char *front, char *back);

//replace_main.c
char	*replace_wave_main(char *str, t_vars *vars);
char	*replace_character_quote(char *str, t_vars *vars);
char	*replace_character(char *str, t_vars *vars);
char	*replace_character_main(char *str, t_vars *vars);

//replace_utils.c
int	check_wave(char *str, int i);
int	is_white_space(char c);
int	replace_index_quote(char *str, int i);
int	find_end_index_env(char	*str, int i);

//replace.c
char	*replace_wave(char *str, t_vars vars, int i);
char	*replace_env(char *str, t_vars vars, int i, int end);
char	*replace_exit_code(char *str, t_vars vars, int i);
char	*replace_env_main(char *str, t_vars *vars);

//split_token.c
int	count_token(char *str);
char	**do_split_token(char *str, int cnt);
char	**split_token_main(char *splited_pipe);

//tokenize_count.c
int	count_av(char **splited_token);
int	count_rd(char **splited_token);

//tokenize.c
t_redir	*tokenize_redir(char **splited_token, int i);
void	tokenize_redir_main(char **splited_token, int i, t_cmd	*cmd);
void	tokenize_av(char **splited_token, t_cmd *cmd);
t_cmd	*tokenize(char **splited_token);

//signal.c
void	handler(int signum);
void	signal_set(void);

#endif