/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:26:08 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/08/08 10:26:08 by hyeonsul         ###   ########.fr       */
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
# include <termios.h>
# include <sys/stat.h>
# include "libft.h"
# include "readline/readline.h"
# include "readline/history.h"

# define PROMPT "minish-1.0$ "
# define STDIN_BACK 3
# define STDOUT_BACK 4
# define STDERR_BACK 5

int		g_exit_code;

enum e_redir_type {
	IN_REDIR = 1,
	OUT_REDIR = 2,
	APPEND = 4,
	HEREDOC = 8
};

enum e_builtin {
	B_ECHO = 1,
	B_CD,
	B_PWD,
	B_EXPORT,
	B_UNSET,
	B_ENV,
	B_EXIT,
	B_NONE
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
	t_env			env;
	t_token			token;
	struct termios	org;
	struct termios	term;
}	t_vars;

// std_ioe.c
void	std_ioe_backup(void);
void	std_ioe_back(void);
// clear.c
void	clear_token(t_token *token);
void	clear_ppc(char **ppc);
void	clear_cmd(t_cmd *cmd);
//signal.c
void	handler(int signum);
void	set_origing(t_vars *vars);
void	signal_set(t_vars *vars);

// env
// util_1.c
void	set_env(t_env *env, char **p_env);
void	print_env(t_node_env *node, void (*visit)(t_node_env *), \
		int builtin_no);
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
void	pipex(int *fd, int INOUT, t_cmd *pipe_chk);
int		fd_ctrl(t_cmd *cmd, int *fd);
// util.c
int		isdir(char	*path);
char	**get_pair(char *str);
char	*strjoin_between_char(char *str1, char *str2, char c);
int		chk_pair(char *str1, char *str2);
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
int		pwd(void);
// export.c
int		export(t_cmd *cmd, t_env *env);
// unset.c
int		unset(t_cmd *cmd, t_env *env);
// env.c
int		env(t_node_env *env);
// exit.c
int		exit_clear(t_vars *vars, t_cmd *cmd);

//parse

//check_readline.c
int		check_valid_redir(char *s, int cnt, int c);
int		check_valid_pipe(char *str);
int		check_valid_quote(char *str);
int		check_splited_pipe(char **splited_pipe);
char	**check_readline(char *str);

//heredoc.c
void	write_heredoc(char *limiter, int fd);
void	signal_heredoc_parent(int signal);
int		heredoc(char *limiter, char *file_name);
char	*get_heredoc_filename(void);
char	*heredoc_main(char *limiter);

//parse_error.c
int		error_parse(int error);
void	error(char *msg);

//parse_free.c
void	free_two_dimen(char	**str);
void	free_replace_env(char *front, char *back, char *env);

//parse_init.c
t_redir	*init_redir(void);
t_cmd	*init_cmd(void);
char	**init_two_dimension(int size);

//parse_utils.c
int		is_character2(char c);
int		check_redirection(char *str);
int		check_only_whitespace(char *str);
int		is_redir(char *str, int i);
char	*heredoc_join_path(char *file_name);

//parse.c
int		do_parse(t_vars *vars, char **splited_pipe);
int		parse(t_vars *vars, char *str);

//replace_env.c
int		find_dollar_end(char *str, int i);
int		new_idx_dollar(char *str, char *new_str, int start, int end);
char	*replace_mid_dollar(char *str, t_vars *vars);
char	*replace_exit_code(char *str, int i);
char	*replace_env(char *str, t_vars vars, int i, int end);

//replace_quote.c
int		find_double_end(char *str, int i);
int		find_single_end(char *str, int i);
char	*remove_double(char *str, int i, int end, t_vars *vars);
char	*remove_single(char *str, int i, int end);

//replace_utils.c
int		is_white_space(char c);
int		is_env(char *str, int i);
int		replace_index_quote(char *str, int i);
int		find_end_index_env(char	*str, int i);
int		check_replace2(char	*str);

//replace.c
char	*replace_dollar(char *str, int i, int end, t_vars *vars);
char	*replace_token_do(char *str, t_vars *vars);
void	replace_new(char **splited_token, t_vars *vars);

//split_pipe.c
int		count_split_pipe(char *s);
int		find_pipe_end(char *str, int i);
int		find_pipe_start(int end);
char	**split_pipe(char *str);

//split_token.c
int		is_character(char *str, int i);
int		count_token(char *str);
char	**do_split_token(char *str, int cnt);
char	**split_token_main(char *splited_pipe, t_vars *vars);

//tokenize_count.c
int		count_av(char **splited_token);
int		count_rd(char **splited_token);

//tokenize.c
t_redir	*tokenize_redir(char **splited_token, int i);
int		tokenize_redir_main(char **splited_token, int i, t_cmd *cmd);
void	tokenize_av(char **splited_token, t_cmd *cmd);
t_cmd	*tokenize(char **splited_token);

#endif