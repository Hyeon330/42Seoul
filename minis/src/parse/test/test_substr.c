#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*pc;
	int		i;

	i = 0;
	while (src[i])
		i++;
	pc = (char *)malloc(sizeof(char) * (i + 1));
	if (pc == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		pc[i] = src[i];
		i++;
	}
	pc[i] = 0;
	return (pc);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	fill_pc_substr(char *pc, char const *s, unsigned int pc_size)
{
	unsigned int	i;

	i = -1;
	while (++i < pc_size)
		pc[i] = s[i];
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pc;
	unsigned int	pc_size;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	pc_size = 0;
	while (s[start + pc_size] && (size_t)pc_size < len)
		pc_size++;
	pc = (char *)malloc(sizeof(char) * (pc_size + 1));
	if (!pc)
		return (NULL);
	pc[pc_size] = 0;
	fill_pc_substr(pc, s + start, pc_size);
	return (pc);
}

int main()
{
	char *str = "this is substring test";
	char *new;

	new = ft_substr(str, 5, 2);
	printf("%s\n", new);
}