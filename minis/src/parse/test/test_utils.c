#include "test.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize && *(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (dstsize)
	{
		if (i == dstsize)
			*(dest + dstsize - 1) = 0;
		else
			*(dest + i) = 0;
	}
	return (ft_strlen(src));
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*_s1;
	unsigned char	*_s2;
	size_t			i;

	_s1 = (unsigned char *)s1;
	_s2 = (unsigned char *)s2;
	i = -1;
	while (++i < n)
	{
		if (!_s1[i] || !_s2[i] || _s1[i] != _s2[i])
			return (_s1[i] - _s2[i]);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pc;
	char	*copy;

	pc = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	copy = pc;
	if (!pc)
		return (NULL);
	while (*s1)
		*pc++ = *s1++;
	while (*s2)
		*pc++ = *s2++;
	*pc = 0;
	return (copy);
}

int	cnt_size(int n)
{
	int	cnt;

	cnt = 0;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

void	input_pc(char *pc, int n, int n_size, int sign)
{
	while (n)
	{
		pc[--n_size] = (n % 10) * sign + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*pc;
	int		sign;
	int		n_size;

	n_size = cnt_size(n);
	if (!n)
		return (ft_strdup("0"));
	sign = 1;
	if (n < 0)
		pc = (char *)malloc(sizeof(char) * ++n_size + 1);
	else
		pc = (char *)malloc(sizeof(char) * n_size + 1);
	if (!pc)
		return (NULL);
	pc[n_size] = 0;
	if (n < 0)
	{
		pc[0] = '-';
		sign *= -1;
	}
	input_pc(pc, n, n_size, sign);
	return (pc);
}
