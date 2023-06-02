/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_pre_parse_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkoh <juwkoh@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 07:15:32 by juwkoh            #+#    #+#             */
/*   Updated: 2023/06/02 07:15:32 by juwkoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*check_input_env_home_qt(char *new, char c, bool *qt)
{
	*qt = !(*qt);
	return (strjoinchar_free(new, c));
}

char	*parse_home(char *path, t_tree env)
{
	char	*home_path;

	if (!path)
		return (NULL);
	home_path = ft_strdup(search(env.root, "HOME"));
	return (home_path);
}

static char	*parse_env(char *inp, int i, t_tree env)
{
	char	*key;
	char	*value;
	char	c;

	if (inp[i] && inp[i] == '?')
		return (ft_itoa(g_exit_code));
	key = ft_calloc(2, sizeof(char));
	while (inp[i] && inp[i] != ' ')
	{
		c = inp[i];
		key = strjoinchar_free(key, c);
		i++;
	}
	value = search(env.root, key);
	free_ptr(key);
	if (!value)
		return (NULL);
	return (value);
}

void	check_input_env_home_dollar(char **new, char *s, int *i, t_tree env)
{
	*new = strjoin_free(*new, parse_env(s, *i + 1, env), false);
	if (s[*i + 1] == '?')
			(*i)++;
	else
		while (s[*i + 1] && s[*i + 1] != ' ' && s[*i + 1] != '$')
			(*i)++;
}

char	*check_input_env_home(char *s, t_tree env)
{
	int		i;
	char	*new;
	bool	sq;
	bool	dq;

	i = -1;
	sq = false;
	dq = false;
	new = ft_calloc(1, sizeof(char));
	while (s[++i])
	{
		if (s[i] == '\'')
			new = check_input_env_home_qt(new, s[i], &sq);
		else if (s[i] == '"')
			new = check_input_env_home_qt(new, s[i], &dq);
		else if (!sq && s[i] == '$' && s[i + 1])
			check_input_env_home_dollar(&new, s, &i, env);
		else if (!sq && !dq && (((i != 0 && s[i - 1] == ' ') || i == 0)
				&& s[i] == '~'))
			new = strjoin_free(new, parse_home(s + i, env), true);
		else
			new = strjoinchar_free(new, s[i]);
	}
	free_ptr(s);
	return (new);
}
