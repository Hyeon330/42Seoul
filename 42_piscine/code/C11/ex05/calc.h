/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:25:11 by chajung           #+#    #+#             */
/*   Updated: 2022/10/21 00:17:39 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

# include <unistd.h>

int		plus(int a, int b);
int		minus(int a, int b);
int		multiplication(int a, int b);
int		division(int a, int b);
int		modulo(int a, int b);
void	ft_putchar(char c);
void	ft_print(int nb);
void	ft_putnbr(int nb);
int		check_isspace(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		calculater(int num1, char operator, int num2);
void	do_op(char *char_num1, char *operator, char *char_num2);

#endif
