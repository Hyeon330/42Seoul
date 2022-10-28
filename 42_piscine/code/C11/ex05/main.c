/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:53:44 by chajung           #+#    #+#             */
/*   Updated: 2022/10/21 00:16:47 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	calculator(int num1, char operator, int num2)
{
	int	(*calc[5])(int, int);
	int	result;

	result = 1;
	calc[0] = plus;
	calc[1] = minus;
	calc[2] = multiplication;
	calc[3] = division;
	calc[4] = modulo;
	if (operator == '+')
		result = (calc[0])(num1, num2);
	else if (operator == '-')
		result = (calc[1])(num1, num2);
	else if (operator == '*')
		result = (calc[2])(num1, num2);
	else if (operator == '/')
		result = (calc[3])(num1, num2);
	else if (operator == '%')
		result = (calc[4])(num1, num2);
	return (result);
}

void	do_op(char *char_num1, char *operator, char *char_num2)
{
	int	num1;
	int	num2;
	int	result;

	num1 = ft_atoi(char_num1);
	num2 = ft_atoi(char_num2);
	if (ft_strlen(operator) != 1 || (*operator != '+' && *operator != '-'\
	&& *operator != '*' && *operator != '/' && *operator != '%'))
		write(1, "0", 1);
	else if (*operator == '/' && num2 == 0)
		write(1, "Stop : division by zero", 23);
	else if (*operator == '%' && num2 == 0)
		write(1, "Stop : modulo by zero", 21);
	else
	{
		result = calculator(num1, operator[0], num2);
		ft_putnbr(result);
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
		do_op(argv[1], argv[2], argv[3]);
	return (0);
}
