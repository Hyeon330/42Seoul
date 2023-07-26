/*
char	*replace_exit_code(char *str, t_vars vars)
{
	char	*exit_code;
	char	*temp;

	temp = str;
	exit_code = ft_itoa(vars.exit_code);
	str = ft_substr(str, 2, ft_strlen(str) - 1);
	free(temp);

}

char	*replace_wave(char *str, t_vars vars)
{
	char	*home_path;
	char	*temp;
	char	*result;

	temp = str;
	home_path = ft_strdup(search_env(vars.env.root, "HOME"));
	str = ft_substr(str, 1, ft_strlen(str) - 1);
	free(temp);
	result = ft_strjoin(home_path, str);
	free(home_path);
	free(str);
	return (result);
}

char	*replace_character(char *str, t_vars vars)
{
	char	**splited;
	char	*result;
	//char	*temp;
	int		i;

	splited = ft_split(str, ' ');
	if (!splited)
		error("malloc error");
	i = 0;
	while (splited[i])
	{
		if (splited[i][0] == '~' || splited[i][0] == '$')
		{
			//temp = splited[i];//이걸 없애도 되도록 짜보자->줄수줄이기
			if (splited[i][0] == '~')
				splited[i] = replace_wave(splited[i], vars);
			else if (splited[i][1] == '?')
				splited[i] = replace_exit_code(splited[i], vars);
			else
				splited[i] = replace_env(splited[i], vars);
			//free(temp);
		}
		i++;
	}
	result = replaced_join(splited);
	free_dimensional_array(splited);
	return (result);
}*/

#include "minishell.h"

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
		else if (str[i] == '$')
		{
			cnt++;
			i++;
		}
		i++;
	}
	return (cnt);
}

char	*replace_wave(char	*str, t_vars vars)
{
	char	*home_path;
	char	*temp;
	char	*result;

	temp = str;
	home_path = ft_strdup(search_env(vars.env.root, "HOME"));
	if (str[1] == '\0')
		return (home_path);
	else
	{
		temp = str;
		str = ft_substr(str, 1, ft_strlen(str) - 1);
		free(temp);
		result = ft_strjoin(home_path, str);
		free(str);
		free(home_path);
	}
	return (result);
}

char	*replace_env(char *str, t_vars vars, int i)
{
	char	*env;
	char	*front;
	char	*temp;
	char	*result;

	front = NULL;
	env = ft_substr(str, i, ft_strlen(str) - 1);//검색할 환경변수
	temp = env;
	env = ft_strdup(search_env(vars.env.root, env));
	free(temp);
	front = ft_substr(str, 0, i);//환경변수 앞부분짜름 //if (i != 0) 조건 안필요할거같아서 지움
	result = ft_strjoin(front, env);
	free(str);
	if (front)
		free(front);
	if (env)
		free(env);
	return (result);
}

char	*replace_exit_code(char *str, t_vars vars, int i)
{
	char	*exit_code;
	char	*front;
	char	*back;
	char	*temp;
	char	*result;

	exit_code = ft_itoa(vars.exit_code);
	front = ft_substr(str, 0, i);
	back = ft_substr(str, i + 2, ft_strlen(str) - i + 2);
	temp = ft_strjoin(front, exit_code);
	result = ft_strjoin(temp, back);
	free(str);
	if (front)
		free(front);
	if (back)
		free(back);
	free(temp);
	return (result);
}
//앞뒤로 뭐가있어도 되야됨

char	*replace_character(char *result, t_vars vars)
{
	int	i;

	i = 0;
	if (result[0] == '~' && (result[1] == '/' || result[1] == '\0'))
	{
		result = replace_wave(result, vars);
	}
	while (result[i])
	{
		if (result[i] == '$' || result[i + 1] != '\0')
		{
			if (result[i + 1] == '?')
				result = replace_exit_code(result, vars, i);
			else
				result = replace_env(result, vars, i);
			i = 0;//뒤 인덱스를 넘겨줘도 되는데 찾기 힘들 것 같아서 그냥 처음부터 다시 검사(임시)
		}
		i++;
	}
	return (result);
}