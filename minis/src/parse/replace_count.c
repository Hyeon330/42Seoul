#include "minishell.h"

int	count_env_quote(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == 34)
		{
			i++;
			while (str[i] != 34)
			{
				if (str[i] == '$' && (str[i + 1] != ' ' && \
				str[i + 1] != 34 && str[i + 1] != 39 && str[i + 1] != '$'))
					cnt++;
				i++;
			}
		}
		i++;
	}
	return (cnt);
}//""안의 유효한 $를 세는 함수

int	count_wave(char *s)
{
	int		i;
	int		cnt;
	char	q;

	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (s[i] == 34 || s[i] == 39)
		{
			q = s[i];
			i++;
			while (s[i] != q)
			{
				i++;
			}
		}
		if ((i == 0 || s[i] == ' ') && s[i + 1] == '~')
		{
			i++;
			if (s[i + 1] == '\0' || s[i + 1] == ' ' || s[i + 1] == '/')
				cnt++;
		}
	}
	return (cnt);
}

int	count_env(char *str)
{
	int		i;
	int		cnt;
	char	q;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			q = str[i];
			i++;
			while (str[i] != q)
			{
				i++;
			}
		}
		if (str[i] == '$' && (str[i + 1] != '\0' && str[i + 1] != ' ' && \
		str[i + 1] != 34 && str[i + 1] != 39 && str[i + 1] != '$'))
			cnt++;
		i++;
	}
	return (cnt);
}