#include "minishell.h"

char	*replace_wave(char *str, t_vars vars, int i)
{
	char	*home_path;
	char	*temp1;
	char	*temp2;
	char	*result;
	char	*old_result;

	home_path = ft_strdup(search_env(vars.env.root, "HOME"));//왜 밑줄?
	temp1 = ft_substr(str, 0, i); //물결전까지 자름
	temp2 = ft_substr(str, i + 1, ft_strlen(str) - 1);
	result = ft_strjoin(temp1, home_path);
	old_result = result;
	result = ft_strjoin(result, temp2);
	free(old_result);
	free(temp1);
	free(temp2);
	return (result);
}
// **환경변수는 strdup를 이용해서 쓰기!!
char	*replace_exit_code(char *str, t_vars vars, int i)
{
	char	*exit_code;
	char	*temp1;
	char	*temp2;
	char	*result;
	char	*old_result;
	
	exit_code = ft_itoa(vars.exit_code);
	temp1 = ft_substr(str, 0, i);
	temp2 = ft_substr(str, i + 2, ft_strlen(str) - 1);
	result = ft_strjoin(temp1, exit_code);
	old_result = result;
	result = ft_strjoin(result, temp2);
	free(old_result);
	free(temp1);
	free(temp2);
	return (result);
}

int	count_replace(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '~')
			cnt++;
		else if (str[i] == '$' && str[i] == '?')
		{
			cnt++;
			i++;
		}
		i++;
	}
	return (cnt);
}

char	*replace_character(char	*str, t_vars vars, int cnt)
{
	int		i;
	int		j;
	char	*old_str;

	i = 0;
	while (i < cnt)
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == '~' || (str[j] == '$' && str[j] == '?'))
			{
				old_str = str;
				if (str[j] == '~')
					str = replace_wave(str, vars, j);
				else
					str = replace_exit_code(str, vars, j);
				free(old_str);
				break;
			}
			j++;
		}
		i++;
	}
	return (str);
}//환경변수와 exitno를 받아오는 방법과 substr어떻게 작동하는지 다시 보기
//길이 딱 맞는듯?