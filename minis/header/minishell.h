/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:39:03 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/09 22:26:54 by hyeonsul         ###   ########.fr       */
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
# include <errno.h>
# include <dirent.h>
# include <signal.h>

enum e_err {
	DYNAMIC = 0
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
	FIRST = 0,
	PIPE,
	IN_REDIR,
	OUT_REDIR,
	HERE_DOC,
	APPEND_MODE
};

typedef struct s_cmd {
	char	*path;
	char	**av;
	int		ac;
	int		type;
}	t_cmd;

typedef struct s_list {
	void	*content;
	t_list	*next;
}	t_list;

// builtin.c
void	builtin(int builtin_no, int ac, char **av);

// error.c
void	ft_error(int e_no);

// libft.a
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif