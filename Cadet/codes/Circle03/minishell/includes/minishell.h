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
# include <sys/stat.h>
# include "libft.h"
# include "readline/readline.h"
# include "readline/history.h"

# define PROMPT "\033[95mMiniShell$ \033[39m"

enum e_err {
	DYNAMIC = 0,
	ISADIR,
	CNF,
	OLDPWD_NOT_SET,
	HOME_NOT_SET,
	CD_NADIR,
	EXIT_TOO_MANY,
	EXIT_NUM,
	OPEN = 32,
	FORK,
	PIPE
};

enum e_builtin {
	ECHO = 1,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
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
	char			*cmd;
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

typedef struct s_tree {
	t_env	*root;
	size_t	size;
}	t_tree;

typedef struct s_vars {
	t_tree	env;
	t_cmd	**cmds;
	int		cmds_cnt;
}	t_vars;

// main.c
void	free_cmds(t_vars *vars);

// exec.c
void	exec(t_vars *vars);

// builtin.c
int		builtin(int builtin_no, t_cmd *cmd, t_vars *vars);
int		isbuiltin(char *cmd);

// builtin/cmds
int		echo(t_cmd *cmd);
int		cd(t_cmd *cmd, t_tree *env);
int		pwd(t_env *root);
int		export(t_cmd *cmd, t_tree *env);
int		unset(t_cmd *cmd, t_tree *env);
int		env(t_env *envp);
int		exit_clear(t_cmd *cmd, t_vars *vars);

// execution.c
int		isdir(char	*path);
void	execute(t_cmd *cmd, t_vars *vars);

// fd_ctrl.c
void	pipex(int *fd, int INOUT);
int		fd_ctrl(t_cmd *cmd, int pipe_chk, int *fd);

// redirection.c
int		in_redir(t_cmd *cmd);
int		out_redir(t_cmd *cmd);

// tree1.c
void	insert(t_tree *tree, char *key, char *val);

// tree2.c
char	*search(t_env *node, char *key);
void	delete_(t_tree *tree, char *key);

// tree_order.c
void	inorder(t_env *node, void (*visit)(t_env *), int builtin_no);
void	get_envp(t_env *node, char ***envp, int *idx);
void	free_env(t_env *node);

// signal_handler.c
void	sigint_handler(int signum);

t_cmd	*lstcmd_new(void);
t_cmd	*lstcmd_last(t_cmd *list);

/// ms_str.c
int		ms_strncmp(char *s1, char *s2, size_t n);
int		ms_strcmp(char *s1, char *s2);
char	*ms_strjoin(char *s1, char *s2);
char	*ms_strnew(int size);
char	*ms_strtrim_free(char *s, char *set);

char	*strjoinchar(char const *str, char c);
char	*strjoinchar_free(char *str, char c);
char	*strjoin_free(char *s1, char *s2, bool free_both);

// ms_tuils.c
void	*ms_calloc(size_t count, size_t size);

// parse.c
int		is_redir(char *str);
int		parse(t_cmd ***cmds, int *cmds_cnt, char *strln);

// pre parse
char	*pre_parse(char *inln, t_tree env);

//  free_utils.c 
void	free_str_array(char **str_array);
void	free_ptr(void *ptr);
void	free_ptr1(void **ptr);
char	**split_pipe(char *s, int *cnt);
void	get_pipe_wordcnt_pass_qt(char **s);

// build_nodes.c
void	build_nodes(t_cmd **root, char **tok, int tokcnt);

// build_cmd_argv.c
char	**build_cmd_argv(char **tok, int *ac);
int		get_tokcnt(char **tok);
void	get_cmd_argv_word(char *argv_j, char *tok_i, int wordlen);
char	*get_cmd_from_av(char *av0);

// pre_parse_env.c
char	*check_input_env_home(char *s, t_tree env);

// split_tok.c
char	**split_tok(char *s);

// split_tok2.c
void	split_tok_get_wordcnt_qt(char **s, int *wordcnt, char c);
void	split_tok_get_wordcnt_rdr(char **s, int *wordcnt, char c);
void	split_tok_get_wordcnt_qt2(char ***s, char c);
void	split_tok_get_wordcnt2_det(char **s);

// split_tok3.c
int		split_tok_get_wordlen_qt(char *s, int *i, char c);
int		split_tok_get_wordlen_rdr(char *s, int *i, char c);
int		split_tok_get_wordlen2_det2(char *s, int **i, char c);
int		split_tok_get_wordlen2_det(char *s, int *i);

// error.c
int		ft_error(int e_no, char *str);
int		cd_error(int e_no, char *str);
int		exit_error(int e_no, char *str);
int		g_exit_code;

#endif