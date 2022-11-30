/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:17:46 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/11/30 22:18:10 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	count_flag(const char *format, t_args *lst)
{
	if ((*format == ' ' || *format == '+') && \
		(lst->spec == 'd' || lst->spec == 'i'))
	{
		lst->flag_size = 1;
		if (lst->flag == 0 || lst->flag == ' ')
			lst->flag = *format;
	}
	else if (*format == '#' && (lst->spec == 'x' || lst->spec == 'X'))
	{
		lst->flag_size = 2;
		lst->flag = *format;
	}
}

void	count_prec(const char **format, t_args *lst)
{
	lst->prec_size = 0;
	(*format)++;
	lst->prec_cnt++;
	while (**format >= '0' && **format <= '9')
	{
		if (lst->spec == 'd' || lst->spec == 'i' || lst->spec == 'u' || \
			lst->spec == 'x' || lst->spec == 'X' || lst->spec == 'p' || \
			lst->spec == 's')
			lst->prec_size = lst->prec_size * 10 + (**format - '0');
		lst->prec_cnt++;
		(*format)++;
	}
	lst->field_len += lst->prec_cnt;
}

void	count_width(const char **format, t_args *lst)
{
	lst->width_size = 0;
	while (**format >= '0' && **format <= '9')
	{
		lst->width_size = lst->width_size * 10 + (**format - '0');
		lst->width_cnt++;
		(*format)++;
	}
	lst->field_len += lst->width_cnt;
}

void	count_arg(va_list *ap, t_args *lst)
{
	if (lst->spec == '%')
		lst->arg_size = 1;
	else if (lst->spec == 'c')
	{
		va_arg(*ap, int);
		lst->arg_size = 1;
	}
	else if (lst->spec == 's')
		lst->arg_size = count_str(va_arg(*ap, char *), lst);
	else if (lst->spec == 'p')
	{
		lst->arg_size = count_hex((unsigned long) va_arg(*ap, void *), lst);
		lst->flag_size = 2;
		lst->flag = '#';
	}
	else if (lst->spec == 'd' || lst->spec == 'i')
		lst->arg_size = count_int(va_arg(*ap, int), lst);
	else if (lst->spec == 'u')
		lst->arg_size = count_uint(va_arg(*ap, unsigned int), lst);
	else if (lst->spec == 'x' || lst->spec == 'X')
		lst->arg_size = count_hex((unsigned int) va_arg(*ap, int), lst);
}
