#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[l])
	{
		l++;
	}
	while (i + 1 < size && i < l)
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (l);
}

int	count_s(char const *s, char c)
{
	int	str_n;

	str_n = 0;
	while (*s)
	{
		if (*s != c)
		{
			str_n++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (str_n);
}

int	count_c(char const *s, char c)
{
	int	cnt;

	cnt = -1;
	while (s[++cnt] && s[cnt] != c)
		;
	return (cnt);
}

void	fill_pc_split(char **ppc, char const *s, int ppc_i, int pc_size)
{
	int	pc_i;

	pc_i = -1;
	while (++pc_i < pc_size)
		ppc[ppc_i][pc_i] = s[pc_i];
}

int	fill_ppc(char **ppc, char const *s, char c)
{
	int		ppc_i;
	int		pc_size;

	ppc_i = -1;
	while (*s)
	{
		pc_size = count_c(s, c);
		if (pc_size)
		{
			ppc[++ppc_i] = (char *)malloc(sizeof(char) * (pc_size + 1));
			if (!ppc[ppc_i])
				return (0);
			ppc[ppc_i][pc_size] = 0;
			fill_pc_split(ppc, s, ppc_i, pc_size);
			s += pc_size;
		}
		else
			s++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ppc;
	int		str_n;
	int		i;

	if (!s)
		return (NULL);
	str_n = count_s(s, c);
	ppc = (char **)malloc(sizeof(char *) * (str_n + 1));
	if (!ppc)
		return (NULL);
	ppc[str_n] = NULL;
	if (!fill_ppc(ppc, s, c))
	{
		i = -1;
		while (ppc[++i] && i < str_n)
			free(ppc[i]);
		free(ppc);
		return (NULL);
	}
	return (ppc);
}
//ft_split

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*c_src;
	int		l;
	int		i;

	l = 0;
	i = 0;
	c_src = (char *)src;
	while (c_src[l])
	{
		l++;
	}
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (str == 0)
		return (0);
	while (i < l)
	{
		str[i] = c_src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	if (s == 0)
		return (0);
	if (start > s_len || len == 0)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	error(char *msg)
{
	perror(msg);
	exit(errno);
}

int	count_quote(char *str)
{
	char	quote;

	quote = *str;
	while (*str)
	{
		if (*str == quote)
			return (1);
		str++;
	}
	error("wrong quote");
	return (-1);
}

int	count_redirection(char **str)
{
	char	redir;

	redir = **str;
	str++;
	if (**str == '<' || **str== '>')
	{
		if (**str != redir)
			error("no words after redirection");
		*str++;
	}
	/*else if(*(str + 1) == '|')
		error("no words after redirection");*/
	return (1);
}

int	count_token(char *str)
{
//strdup()
	char	*temp;
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;

	temp = str;
	while (*temp)
	{
		if (*temp == 34 || *temp == 39)
			cnt += count_quote(temp);
		if (*temp == '<' || *temp == '>')
			cnt += count_redirection(&temp);
		if (*temp != ' ' && (*(temp + 1) == ' ' || *(temp + 1) == '\0'))//*temp + 1맞는 방법인지 확인하기
			cnt++;
		temp++;
	}
	return (cnt);
}

char	*split_quote(char *s)
{
	char	*result;
	int		end;

	end = 1;
	while (s[end] != s[0])
	{
		end++;
	}
	result = ft_substr(s, 1, end - 1);
	s += end +1;
	return (result);
}//맞는지 확인하기

char	*split_redirection(char *s)
{
	char	*result;

	if (*(s + 1) == *s)
	{
		result = ft_substr(s, 0, 1);
		s += 2;
	}
	else
	{
		result[0] = *s;
		result[1] = '\0';
		s++;
	}
	return (result);
}

char	*split_blank(char *s)
{
	char	*tmp;
	char	*result;

	tmp = s;
	while (*s && *s != ' ')
		*s += 1;
	result = (char *)malloc(sizeof(char) * (s - tmp + 1));
	if (!result)
		return (0);
	ft_strlcpy(result, tmp, s - tmp + 1);
	return (result);
}

void	split_token(char **splited, char *s, int cnt)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
			splited[i++] = split_quote(s);
		else if (*s == '<' || *s == '>')
			splited[i++] = split_redirection(s);
		else if (*s != ' ')
			splited[i++] = split_blank(s);
		else
			s++;
	}
}

char	**split_token_main(char *str)
{
	int		cnt;
	char	**splited;

	cnt = count_token(str);
	splited = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!splited)
		error("malloc error");
	splited[cnt] = NULL;
	split_token(splited, str, cnt);
	return (splited);
}

int main()
{
	char	*str = "infile ls -al";
	char	**splited;

	splited = split_token_main(str);
	for(int i = 0; splited[i] != NULL; i++)
	{
		printf("%s\n", splited[i]);
	}
}//split을 다 index가지고 움직이도록 바꿔야겠는걸~?!omg
