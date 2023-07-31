#include "minishell.h"

char	*replace_wave(char *str, t_vars vars, int i)
{
	char	*home_path;
	char	*front;
	char	*back;
	char	*result;
	char	*temp;

	home_path = ft_strdup(search_env(vars.env.root, "HOME"));
	front = ft_substr(str, 0, i);
	back = ft_substr(str, i + 1, ft_strlen(str) - i + 1);
	temp = ft_strjoin(front, home_path);
	result = ft_strjoin(result, back);
	free_replace_wave(temp, home_path, front, back);
	return (result);
}//str은 free 대상이 아님!

char	*replace_env(char *str, t_vars vars, int i, int end)
{
	char	*env;
	char	*front;
	char	*back;
	char	*result;
	char	*temp;

	front = ft_substr(str, 0, i);
	temp = ft_substr(str, i + 1, end - i);
	back = ft_substr(str, end + 1, ft_strlen(str) - end + 1);
	if (search_env(vars.env.root, temp) == NULL)
		env = ft_strdup("");
	else
		env = ft_strdup(search_env(vars.env.root, temp));
	free(temp);
	temp = ft_strjoin(front, env);
	result = ft_strjoin(temp, back);
	free_replace_env(front, back, env);
	return (result);
}

char	*replace_exit_code(char *str, t_vars vars, int i)
{
	char	*exit_code;
	char	*front;
	char	*back;
	char	*temp;
	char	*result;

	front = ft_substr(str, 0, i);
	back = ft_substr(str, i + 2, ft_strlen(str) - i + 2);
	exit_code = ft_itoa(vars.exit_code);
	temp = ft_strjoin(front, exit_code);
	result = ft_strjoin(temp, back);
	free(temp);
	if (front)
		free(front);
	if (back)
		free(back);
	free(exit_code);
	return (result);
}

char	*replace_env_main(char *str, t_vars *vars)
{
	int		i;
	char	*old;
	char	*new;

	i = 0;
	old = NULL;
	new = NULL;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
			i = replace_index_quote(str, i);
		if (str[i] == '$' && (str[i + 1] == '?' || (str[i + 1] != '\0' && is_white_space(str[i + 1]) != 1 && str[i + 1] != 34 && str[i + 1] != 39 && str[i + 1] != '$' && str[i + 1] != '~')))
		{
			if (old)
				free(old);
			old = new;
			if (str[i + 1] == '?')
				new = replace_exit_code(str, *vars, i);
			else
				new = replace_env(str, *vars, i, find_end_index_env(str, i));
			str = new;
			i = 0;
			continue ;
		}
		i++;
	}
	if (old)
		free(old);
	return (str);
}