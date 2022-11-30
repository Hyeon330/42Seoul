/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soominpa <soominpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:23:12 by soominpa          #+#    #+#             */
/*   Updated: 2022/10/02 20:14:31 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, char start, char middle, char end)
{
	ft_putchar(start);
	if (x > 1)
	{
		x -= 2;
		while (x--)
			ft_putchar(middle);
		ft_putchar(end);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
	else
		print_line(x, 'A', 'B', 'C');
	if (y > 1)
	{
		y -= 2;
		while (y--)
			print_line(x, 'B', ' ', 'B');
		print_line(x, 'C', 'B', 'A');
	}
}