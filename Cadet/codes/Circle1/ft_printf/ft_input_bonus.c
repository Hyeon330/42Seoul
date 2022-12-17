/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:06:01 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/30 22:20:27 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	input_flag(char *pc, t_args *lst, int *pc_i)
{
	if (lst->flag == '#')
	{
		pc[*pc_i] = '0';
		if (lst->spec == 'X')
			pc[*pc_i + 1] = 'X';
		else
			pc[*pc_i + 1] = 'x';
	}
	else
	{
		if (lst->flag == '+')
			pc[*pc_i] = '+';
		else if (lst->flag == ' ')
			pc[*pc_i] = ' ';
	}
	*pc_i += lst->flag_size;
}

void	input_arg(char *pc, va_list *ap, t_args *lst, char const *format)
{
	if (lst->spec == '%')
		*pc = '%';
	else if (lst->spec == 'c')
		*pc = va_arg(*ap, int);
	else if (lst->spec == 's')
		input_str(pc, va_arg(*ap, char *), lst);
	else if (lst->spec == 'p')
		input_hex(pc, (unsigned long) va_arg(*ap, void *), lst->spec);
	else if (lst->spec == 'd' || lst->spec == 'i')
		input_int(pc, va_arg(*ap, int));
	else if (lst->spec == 'u')
		input_num_base(pc, (unsigned int) va_arg(*ap, int), "0123456789", 10);
	else if (lst->spec == 'x' || lst->spec == 'X')
		input_hex(pc, (unsigned int) va_arg(*ap, unsigned int), lst->spec);
	else if (lst->arg_size)
		*pc = *(format + lst->field_len);
}

void	fill_sp(char *pc, int *pc_i, t_args *lst)
{
	int	sp;
	int	sp_size;

	if (lst->prec_size > lst->arg_size)
		sp_size = lst->one_arg_total_size - (lst->prec_size + lst->flag_size);
	else
		sp_size = lst->one_arg_total_size - (lst->arg_size + lst->flag_size);
	if (lst->zero && !lst->prec_cnt && !lst->left)
		sp_size = 0;
	sp = -1;
	while (++sp < sp_size)
		pc[(*pc_i)++] = ' ';
}

void	fill_zero(char *pc, int *pc_i, t_args *lst)
{
	int	zero;
	int	zero_size;

	zero_size = lst->prec_size - lst->arg_size;
	if (lst->zero && !lst->prec_cnt && !lst->left)
		zero_size = lst->one_arg_total_size - (lst->flag_size + lst->arg_size);
	zero = -1;
	while (++zero < zero_size)
		pc[(*pc_i)++] = '0';
}

void	input_pc(char *pc, va_list *ap, const char *format, t_args *lst)
{
	int	pc_i;

	pc_i = 0;
	while (*++format)
	{
		if (*format == '%')
		{
			if (!lst->left)
				fill_sp(pc, &pc_i, lst);
			if (lst->flag)
				input_flag(pc, lst, &pc_i);
			fill_zero(pc, &pc_i, lst);
			input_arg(pc + pc_i, ap, lst, format);
			pc_i += lst->arg_size;
			if (lst->left)
				fill_sp(pc, &pc_i, lst);
			format += lst->field_len;
			lst = lst->next;
		}
		else
			pc[pc_i++] = *format;
	}
}
