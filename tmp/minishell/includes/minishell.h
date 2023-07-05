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

enum e_redir_type {
	IN_REDIR = 0,
	OUT_REDIR,
	APPEND
}

typedef struct s_redirection {
	struct s_redir	*next;
	int				type;
}	t_redirection;

typedef struct s_cmd {
	struct s_cmd	*next;
	t_redirection	*red;
	char			*cmd;
	char			**av;
	int				ac;
}	t_cmd;

typedef struct s_tokken {
	t_cmd	*cmd;
	int		size;
}	t_tokken;

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

#endif