#include "test.h"

int	check_wave(char *str, int i)
{
	int	result;

	result = 0;
	if (str[i] != '~')
		return (0);
	if (i == 0 && (str[i + 1] == '/' || str[i + 1] == ' '))
		result = 1;
	if (i != 0 && str[i - 1] == ' ' && (str[i + 1] == '/' || str[i + 1] == ' ' || str[i + 1] == '\0'))
		result = 1;
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
		if (str[i] == '~' && (check_wave(str, i) == 1))
			cnt++;
		if (str[i] == '$' && str[i] != '\0')
			cnt++;
		i++;
	}
	return (cnt);
}

char	*replace_wave(char *str, int i)
{
	char	*home_path;
	char	*front;
	char	*back;
	char	*result;
	char	*old_result;

	home_path = "EJ";	
	front = ft_substr(str, 0, i); //물결전까지 자름
	back = ft_substr(str, i + 1, ft_strlen(str) - 1);
	result = ft_strjoin(front, home_path);
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
	char	*str = "echo ~";
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
			if (check_wave(result, j) == 1) //이걸 다 합칠 수 있으면 좋을텐데
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

//gcc -g  test_replace_count.c test_utils.c