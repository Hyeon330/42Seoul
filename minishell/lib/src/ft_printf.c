/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:27:20 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 20:50:47 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_list(t_args **lst)
{
	t_args	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

char	*make_malloc(va_list *ap, const char *format, \
		t_args **lst, int *pc_size)
{
	char	*pc;

	take_info(ap, format - 1, lst, pc_size);
	if (*pc_size < 0)
		return (NULL);
	pc = (char *)malloc(sizeof(char) * (*pc_size + 1));
	if (!pc)
		return (NULL);
	pc[*pc_size] = 0;
	return (pc);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_args	*arg_lst;
	char	*pc;
	int		pc_size;

	va_start(ap, format);
	arg_lst = NULL;
	pc_size = 0;
	pc = make_malloc(&ap, format, &arg_lst, &pc_size);
	if (!pc)
	{
		clear_list(&arg_lst);
		va_end(ap);
		return (-1);
	}
	va_end(ap);
	va_start(ap, format);
	input_pc(pc, &ap, format - 1, arg_lst);
	write(1, pc, pc_size);
	clear_list(&arg_lst);
	free(pc);
	va_end(ap);
	return (pc_size);
}
