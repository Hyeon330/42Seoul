/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:01:59 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/11 17:35:30 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_ck(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	blank_chk(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	num_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	num;
	int	tmp;
	int	sign;
	int	base_len;

	base_len = base_ck(base);
	if (base_len > 1)
	{
		sign = 1;
		i = blank_chk(str, &sign);
		num = 0;
		tmp = 0;
		while (str[i])
		{
			tmp = num_base(str[i], base);
			if (tmp == -1)
				return (num);
			num *= base_len;
			num += tmp * sign;
			i++;
		}
		return (num);
	}
	return (0);
}
