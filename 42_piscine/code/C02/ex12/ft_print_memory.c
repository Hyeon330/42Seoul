/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:42:36 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/06 13:05:12 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num_to_hex(unsigned long long num, int i)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num < 16)
	{
		while (i--)
			write(1, "0", 1);
	}
	if (num >= 16)
		print_num_to_hex(num / 16, i - 1);
	write(1, &hex[num % 16], 1);
}

void	print_char_to_hex(unsigned char *ad_ch, int size)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		write(1, &hex[*(ad_ch + i) / 16], 1);
		write(1, &hex[*(ad_ch + i) % 16], 1);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
}

void	print_one_line(unsigned char *ad_ch, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (*(ad_ch + i) >= 32 && *(ad_ch + i) <= 126)
			write(1, (ad_ch + i), 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_hex_str(unsigned char *ad_ch, int num)
{
	print_char_to_hex(ad_ch, num);
	print_one_line(ad_ch, num);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ad_ch;
	int				i;

	ad_ch = (unsigned char *) addr;
	i = size;
	while (i > 0)
	{
		print_num_to_hex((unsigned long long) ad_ch, 15);
		write(1, ": ", 2);
		if (i >= 16)
			print_hex_str(ad_ch, 16);
		else
			print_hex_str(ad_ch, i);
		write(1, "\n", 1);
		ad_ch += 16;
		i -= 16;
	}
	return (addr);
}
