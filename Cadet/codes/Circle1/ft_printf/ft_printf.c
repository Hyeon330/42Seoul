/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:08:05 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/30 22:40:59 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_s(char *str, int *cnt)
{
	if (!str)
		*cnt += ft_putstr_fd("(null)", 1);
	else
		*cnt += ft_putstr_fd(str, 1);
}

void	find_spec(va_list ap, char spec, int *cnt)
{
	char	*hex;
	char	*_hex;

	hex = "0123456789abcdef";
	_hex = "0123456789ABCDEF";
	if (spec == '%')
		*cnt += ft_putchar_fd(spec, 1);
	else if (spec == 'c')
		*cnt += ft_putchar_fd(va_arg(ap, int), 1);
	else if (spec == 's')
		spec_s(va_arg(ap, char *), cnt);
	else if (spec == 'p')
	{
		*cnt += ft_putstr_fd("0x", 1);
		*cnt += ft_putnbr_base((unsigned long) va_arg(ap, void *), hex);
	}
	else if (spec == 'd' || spec == 'i')
		*cnt += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (spec == 'u')
		*cnt += ft_putunbr(va_arg(ap, unsigned int));
	else if (spec == 'x')
		*cnt += ft_putnbr_base((unsigned int) va_arg(ap, int), hex);
	else if (spec == 'X')
		*cnt += ft_putnbr_base((unsigned int) va_arg(ap, int), _hex);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, format);
	cnt = 0;
	while (*format)
	{
		if (*format == '%')
			find_spec(ap, *++format, &cnt);
		else
			cnt += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	return (cnt);
}
