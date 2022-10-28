/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:21:26 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/20 12:20:56 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_strcat(char *s1, char *s2)
{
	int	i;

	while (*s1)
		s1++;
	i = 0;
	while (s2[i + 1])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i++] = '\n';
	s1[i] = '\0';
}

char	*standard_read(void)
{
	int		i;
	int		length;
	char	buf1[3000];
	char	*buf2;

	buf2 = (char *)malloc(sizeof(char) * 2000000);
	buf2[0] = 0;
	i = 0;
	while (i < 3000)
		buf1[i++] = 0;
	length = read(0, buf1, 3000);
	while (length > 0)
	{
		ft_strcat(buf2, buf1);
		i = 0;
		while (i < 3000)
			buf1[i++] = 0;
		length = read(0, buf1, 3000);
	}
	return (buf2);
}

void	one_solution(t_info tif, int index)
{
	tif.buf = standard_read();
	get_real_info_input(&tif, &index);
	solution(tif, index);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		index;
	t_info	tif;

	i = 1;
	index = 0;
	while (i < argc)
	{
		index = 0;
		if (get_real_info_file(&tif, argv[i], &index))
			solution(tif, index);
		else
			write(2, "map error\n", 11);
		if (i != argc - 1)
			ft_putstr("\n");
		i++;
	}
	if (argc == 1)
		one_solution(tif, index);
	return (0);
}
