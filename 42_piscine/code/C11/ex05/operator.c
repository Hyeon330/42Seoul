/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:05:32 by chajung           #+#    #+#             */
/*   Updated: 2022/10/21 00:18:28 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"

int	plus(int a, int b)
{
	return (a + b);
}

int	minus(int a, int b)
{
	return (a - b);
}

int	multiplication(int a, int b)
{
	return (a * b);
}

int	division(int a, int b)
{
	return (a / b);
}

int	modulo(int a, int b)
{
	return (a % b);
}
