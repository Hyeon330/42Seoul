#include "test.h"

int	check_env(char *str, int i)
{
	if (str[i] != '$')
		return (0);
	if (str[i + 1] == '?')
		return (2);
	if (str[i + 1] != '\0' && str[i + 1] != 32 && \
	(str[i + 1] < 9 || str[i + 1] > 13))
		return (1);
	return (0);
}

char	*replace_exit_code(char *str, int i)
{
	char	*env;
	char	*front;
	char	*back;
	char	*result;
	char	*old_result;

	env = "env";
	front = ft_substr(str, 0, i); //물결전까지 자름
	back = ft_substr(str, i + 1, ft_strlen(str) - 1);
	result = ft_strjoin(front, env);
	old_result = result;
	result = ft_strjoin(result, back);
	if (old_result)
		free(old_result);
	if (front)
		free(front);
	if (back)
		free(back);
	return (result);
}

char	*replace_env(char *str, int i)
{
	char	*env;
	char	*front;
	char	*back;
	char	*result;
	char	*old_result;

	env = "env";
	front = ft_substr(str, 0, i); //물결전까지 자름
	back = ft_substr(str, i + 1, ft_strlen(str) - 1);
	result = ft_strjoin(front, env);
	old_result = result;
	result = ft_strjoin(result, back);
	if (old_result)
		free(old_result);
	if (front)
		free(front);
	if (back)
		free(back);
	return (result);
}

int main()
{
	char	*str = "$HOME $?";
	char	*result;
	int		cnt;
	int		i;
	int		j;

	i = 0;
	result = str;
	cnt = count_replace(str);
	printf("cnt: %d\n", cnt);
	while (i < cnt)
	{
		j = 0;
		while (result[j])
		{
			if (check_wave(result, j) == 1)
			{
				result = replace_wave(result, j);
				break;
				//printf("result: %s\n", result);
			}
			j++;
		}
		i++;
	}
	printf("%s\n", result);
}

/*
int main()
{
	char	*str = "fdkjd ~? $? dsk$aj$ fsk$HOMWdkaj $";
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (check_env(str, i) != 0)
				cnt++;
		}
		i++;
	}
	printf("cnt : %d\n", cnt);
}//check_env test
*/