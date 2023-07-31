#include "minishell.h"

char	*replace_wave_main(char *str, t_vars *vars)
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
		if (str[i] == '~' && check_wave(str, i) == 1)
		{
			if (old)
				free(old);
			old = new;
			new = replace_wave(str, *vars, i);
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

char	*replace_character_quote(char *str, t_vars *vars)
{
	char	*old;
	char	*new;
	int		i;

	old = NULL;
	new = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			i++;
			while (str[i] != 34)
			{
				if (str[i] == '$' && (str[i + 1] == '?' || (str[i + 1] != '\0' && is_white_space(str[i + 1]) != 1 && str[i + 1] != 34 && str[i + 1] != 39 && str[i + 1] != '~')))
				{
					if (old)
						free(old);
					old = new;
					if (str[i + 1] == '?')
						new = replace_exit_code(str, *vars, i);
					else
						new = replace_env(str, *vars, i, find_end_index_env(str, i));
					str = new;
					i = -1;
					break ;
				}
				i++;
			}
			if (i == -1)
			{
				i = 0;
				continue ;
			}
		}
		i++;
	}
	if (old)
		free(old);
	return (str);
}

char	*replace_character(char *str, t_vars *vars)
{
	char	*new;
	char	*result;

	new = NULL;
	result = NULL;
	if (count_env(str) != 0)
		new = replace_env_main(str, vars);
	if (count_wave(str) != 0)
	{
		if (new != NULL)
		{
			result = replace_wave_main(new, vars);
			free(new);
		}
		else
			result = replace_wave_main(str, vars);
	}
	if (result == NULL)
		return (new);
	return(result);
}

char	*replace_character_main(char *str, t_vars *vars)
{
	char	*new;
	char	*result;

	new = NULL;
	result = NULL;
	if (count_env(str) + count_wave(str) + count_env_quote(str) == 0)
		return (NULL);
	if (count_env(str) + count_wave(str) != 0)
		new = replace_character(str, vars);
	if (count_env_quote(str) != 0)
	{
		if (new != NULL)
		{
			result = replace_character_quote(new, vars);
			free(new);
		}
		else
			result = replace_character_quote(str, vars);
	}
	return (result);
}