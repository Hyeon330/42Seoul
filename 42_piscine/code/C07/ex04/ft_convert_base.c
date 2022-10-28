/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:44:39 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/19 00:02:04 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	base_ck(char *base);
int	ft_atoi_base(char *str, char *base);

int	num_base_len(long long num, long long base_len)
{
	int	i;

	if (!num)
		return (1);
	i = 0;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num)
	{
		num /= base_len;
		i++;
	}
	return (i);
}

char	*putnbr_arr(long long num, char *base, long long base_len)
{
	char	*pc;
	int		i;
	int		num_to_base_size;

	num_to_base_size = num_base_len(num, base_len);
	pc = (char *)malloc(sizeof(char) * (num_to_base_size + 1));
	pc[num_to_base_size] = 0;
	if (!num)
	{
		pc[0] = base[0];
		return (pc);
	}
	if (num < 0)
	{
		num *= -1;
		pc[0] = '-';
	}
	i = 1;
	while (num)
	{
		pc[num_to_base_size - i++] = base[num % base_len];
		num /= base_len;
	}
	return (pc);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long long	num;
	long long	base_len;

	num = (long long) nbr;
	base_len = base_ck(base);
	if (base_len > 1)
	{
		return (putnbr_arr(num, base, base_len));
	}
	return ((void *) 0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (base_ck(base_from) > 1 && base_ck(base_to) > 1)
		return (ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to));
	else
		return ((void *) 0);
}
/*#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_convert_base("-cbeheidgei", "abcdefghij", "0123456789"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "0123456789"));
	printf("%s\n", ft_convert_base("-2147483648", "0123456789", "abcde"));
	printf("%s\n", ft_convert_base("2147483647", "0123456789", "0123456789"));
	printf("%s\n", ft_convert_base("2147483647", "0123456789", "abcdefghij"));
	printf("%s\n", ft_convert_base("2147483647", "0123456789", "abcde"));
	printf("%s\n", ft_convert_base("0", "012345", "abcde"));
	printf("%s\n", ft_convert_base("0", "0", "abcde"));
}*/
