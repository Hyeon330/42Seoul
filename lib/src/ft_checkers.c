/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_count1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:24:44 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 17:41:37 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char	chk_spec(const char *format)
{
	char	*spec;
	int		spec_i;

	spec = "cspdiuxX%";
	while (*format)
	{
		spec_i = -1;
		while (spec[++spec_i])
		{
			if (*format == spec[spec_i])
				return (spec[spec_i]);
		}
		format++;
	}
	return (0);
}

int	chk_field(char c)
{
	char	*field;

	field = "# +-.0123456789";
	while (*field != c)
		field++;
	return (*field);
}

void	set_arg_total_len(const char **format, t_args *lst)
{
	if (!lst->arg_size && !lst->spec)
	{
		lst->one_arg_total_size = 0;
		(*format)--;
	}
	else
	{
		if (lst->spec == 's' && lst->prec_cnt)
			lst->prec_size = lst->arg_size;
		lst->one_arg_total_size = lst->flag_size + lst->arg_size;
		if (lst->one_arg_total_size <= lst->width_size)
			lst->one_arg_total_size = lst->width_size;
		if (lst->one_arg_total_size <= lst->prec_size + lst->flag_size)
		{
			lst->one_arg_total_size = lst->prec_size + lst->flag_size;
			if (lst->minus && !lst->flag_size)
				lst->one_arg_total_size++;
		}
		lst->field_len++;
	}
}
