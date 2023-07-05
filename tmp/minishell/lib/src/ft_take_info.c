/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:50:06 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 20:54:45 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_arg_list(t_args *lst)
{
	lst->next = NULL;
	lst->flag_size = 0;
	lst->width_size = 0;
	lst->width_cnt = 0;
	lst->prec_size = 0;
	lst->prec_cnt = 0;
	lst->arg_size = 0;
	lst->one_arg_total_size = 0;
	lst->left = 0;
	lst->zero = 0;
	lst->minus = 0;
	lst->field_len = 0;
	lst->flag = 0;
	lst->spec = 0;
}

void	proc_field(const char **format, t_args *lst)
{
	if (**format == '#')
		count_flag(*format, lst);
	else if (**format == ' ')
		count_flag(*format, lst);
	else if (**format == '+')
		count_flag(*format, lst);
	else if (**format == '-')
		lst->left = 1;
	else if (**format == '0')
		lst->zero = 1;
	else if (**format == '.')
	{
		count_prec(format, lst);
		lst->field_len--;
		(*format)--;
	}
	else if (**format >= '1' && **format <= '9')
	{
		count_width(format, lst);
		lst->field_len--;
		(*format)--;
	}
}

static t_args	*lstnew(va_list *ap, const char **format)
{
	t_args	*lst;

	(*format)++;
	lst = (t_args *)malloc(sizeof(t_args));
	if (!lst)
		return (NULL);
	init_arg_list(lst);
	lst->spec = chk_spec(*format);
	while (lst->spec != **format)
	{
		if (chk_field(**format))
			proc_field(format, lst);
		else
		{
			lst->arg_size = 1;
			break ;
		}
		(*format)++;
		lst->field_len++;
	}
	count_arg(ap, lst);
	set_arg_total_len(format, lst);
	return (lst);
}

void	conn_list(t_args **lst, t_args *newlst, t_args **tmp)
{
	if (!(*lst))
	{
		*lst = newlst;
		*tmp = *lst;
	}
	else
	{
		(*lst)->next = newlst;
		*lst = (*lst)->next;
	}
}

void	take_info(va_list *ap, const char *format, t_args **lst, int *pc_size)
{
	t_args	*tmp;

	tmp = NULL;
	while (*++format && *pc_size >= 0)
	{
		if (*format == '%')
		{
			conn_list(lst, lstnew(ap, &format), &tmp);
			if (!(*lst))
				*pc_size = -1;
			else
				*pc_size += (*lst)->one_arg_total_size;
		}
		else
			(*pc_size)++;
	}
	*lst = tmp;
}
