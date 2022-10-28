/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soominpa <soominpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:22:24 by soominpa          #+#    #+#             */
/*   Updated: 2022/10/02 20:14:15 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	_atoi(char *str)
{
	int		num;

	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - '0');
	if (*str)
		return (0);
	return (num);
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		rush(_atoi(argv[1]), _atoi(argv[2]));
	else if (argc == 1)
		rush(5, 5);
	return (0);
}
