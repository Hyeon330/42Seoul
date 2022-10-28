/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:35:08 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/17 00:00:15 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

void	str_num(char *str, char *charset, int *str_n)
{
	int	i;
	int	j;
	int	flag;

	flag = 1;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (!charset[j] && flag)
		{
			(*str_n)++;
			flag = 0;
		}
		i++;
	}
}

char	*make_malloc_str_len(char *str, char *charset, int i)
{
	int	j;
	int	cnt;

	cnt = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j] && charset[j] != str[i])
			j++;
		if (!charset[j])
			cnt++;
		else
			break ;
		i++;
	}
	return ((char *)malloc(sizeof(char) * (cnt + 1)));
}

void	input_str(char *pc, char *str, char *charset, int *i)
{
	int	j;
	int	k;

	k = 0;
	while (str[*i])
	{
		j = 0;
		while (charset[j] && charset[j] != str[*i])
			j++;
		if (!charset[j])
			pc[k] = str[*i];
		else
			break ;
		(*i)++;
		k++;
		pc[k] = 0;
	}
}

void	input_2p_str(char **ppc, char *str, char *charset, int str_n)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (k < str_n)
	{
		while (str[i])
		{
			j = 0;
			while (charset[j] && str[i] != charset[j])
				j++;
			if (!charset[j])
			{
				ppc[k] = make_malloc_str_len(str, charset, i);
				input_str(ppc[k], str, charset, &i);
				break ;
			}
			i++;
		}
		k++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ppc;
	int		str_n;

	str_n = 0;
	str_num(str, charset, &str_n);
	ppc = (char **)malloc(sizeof(char *) * (str_n + 1));
	input_2p_str(ppc, str, charset, str_n);
	ppc[str_n] = 0;
	return (ppc);
}

/*int main(void)
{
	char **ppc;
	int num;
	char *str;
	int i;

	str = "12233he23llo321wor44231ld313131";
	i = 0;
	num = 0;
	str_num(str, "123", &num);
	ppc = ft_split(str, "123l"); 

	while (i < num)
	{
		printf("%s\n", ppc[i]);
		i++;
	}
}*/
