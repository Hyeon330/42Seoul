/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:52:31 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/05 08:37:36 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	char			*hex;
	unsigned char	*s;

	s = (unsigned char *) str;
	hex = "0123456789abcdef";
	while (*s)
	{
		if (ft_printable(*s))
			ft_putchar(*s);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex[*s / 16]);
			ft_putchar(hex[*s % 16]);
		}
		s++;
	}
}

/*int main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bi\ten ?");
	return 0;
}*/
