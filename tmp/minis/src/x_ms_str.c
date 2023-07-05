#include "minishell.h"

int	ms_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
	{
		if (!str1[i] || !str2[i] || str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	return (0);
}

int ms_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2) {
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char *ms_strjoin(char *s1, char *s2)
{
	char *newstr;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = ms_strnew(s1_len + s2_len + 1);
	if (!newstr)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		*(newstr + i) = *(s1 + i);
	while (++j < s2_len)
		*(newstr + i++) = *(s2 + j);
	return (newstr);
}

char *ms_strnew(int size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

char	*ms_strtrim_free(char *s, char *set)
{
	char	*new;
	
	if (!s || !set)
		return (NULL);
	new = ft_strtrim(s, set);
	free_ptr(s);
	return (new);
}
