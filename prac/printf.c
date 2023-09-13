#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

int ft_putstr(char *str)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		write(1, str++, 1);
		cnt++;
	}
	return cnt;
}

int spec_s(char *str)
{
	if (str)
		return ft_putstr(str);
	else
		return ft_putstr("(null)");
}

int ft_putunbr_base(unsigned long num, char *base, ssize_t s_base)
{
	int ret;

	ret = 0;
	if (num >= s_base)
		ret = ft_putunbr_base(num / s_base, base, s_base);
	return ret + ft_putchar(base[num % s_base]);
}

int ft_putnbr(int n)
{
	int cnt;
	int	min;

	min = 0;
	cnt = 0;
	if (n < 0)
	{
		cnt += ft_putchar('-');
		if (n == -2147483648)
		{
			min = 1;
			n /= 10;
		}
		n *= -1;
	}
	cnt += ft_putunbr_base((unsigned int) n, "0123456789", 10);
	if (min)
		cnt += ft_putchar('8');
	return cnt;

}

// %cspdiuxX
int	find_spec(va_list ap, char spec)
{
	char	*dig = "0123456789";
	char	*hex[2];

	hex[0] = "0123456789abcdef";
	hex[1] = "0123456789ABCDEF";
	if (spec == '%')
		return ft_putchar(spec);
	else if (spec == 'c')
		return  ft_putchar(va_arg(ap, int));
	else if (spec == 's')
		return spec_s(va_arg(ap, char *));
	else if (spec == 'p')
		return ft_putstr("0x") + ft_putunbr_base((unsigned long) va_arg(ap, void *), hex[0], 16);
	else if (spec == 'd' || spec == 'i')
		return ft_putnbr(va_arg(ap, int));
	else if (spec == 'u')
		return ft_putunbr_base((unsigned int) va_arg(ap, unsigned int), dig, 10);
	else if (spec == 'x')
		return ft_putunbr_base((unsigned int) va_arg(ap, int), hex[0], 16);
	else if (spec == 'X')
		return ft_putunbr_base((unsigned int) va_arg(ap, int), hex[1], 16);
	return 0;
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int		cnt;

	va_start(ap, format);
	cnt = 0;
	while (*format)
	{
		if (*format == '%')
			cnt += find_spec(ap, *++format);
		else
		{
			write(1, format, 1);
			cnt++;
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (cnt);
}

int main()
{
	int cnt;

	cnt = ft_printf("hello %s\n1234=> %d\n", "world", 1234);
	printf("cnt=> 24 == %d\n", cnt);
	cnt = ft_printf("xxx=> %x\nnull=> %s\nXXX=> %X\n", -2147483648, 0, -2147483648);
	printf("cnt=> %d\n", cnt);
	cnt = ft_printf("%");
	printf("???=> %d\n", cnt);
}
