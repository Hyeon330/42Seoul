/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:08:43 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/12/08 23:37:48 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_lst {
	struct s_lst	*next;
	char			*str;
	int				i;
}	t_lst;

// void	func(t_lst *lst, int i)
// {
// 	while (lst)
// 	{
// 		if (lst->i == )
// 	}
// }

// void	put_lst(t_lst *lst)
// {
// 	while (lst)
// 	{
// 		printf("str = %s || i = %d\n", lst->str, lst->i);
// 		lst = lst->next;
// 	}
// }

int	main(void)
{
	// t_lst	*lst, *tmp;
	// int	lst_s, lst_max, lst_s_i;

	// lst = NULL;
	// tmp = NULL;
	// lst_max = 4;
	// lst_s = 0;
	// while (++lst_s <= lst_max)
	// {
	// 	if (!tmp)
	// 	{
	// 		lst = (t_lst *)malloc(sizeof(t_lst));
	// 		tmp = lst;
	// 	}
	// 	tmp->str = (char *)malloc(sizeof(char) * lst_max + 1);
	// 	tmp->str[lst_max] = 0;
	// 	lst_s_i = -1;
	// 	while (++lst_s_i < lst_max)
	// 		tmp->str[lst_s_i] = lst_s + '0';
	// 	tmp->i = lst_s;
	// 	if (lst_s == lst_max)
	// 		tmp->next = NULL;
	// 	else
	// 		tmp->next = (t_lst *)malloc(sizeof(t_lst));
	// 	tmp = tmp->next;
	// }

	// put_lst(lst);
	// printf("----------------\n");

	// tmp = lst;
	// tmp = tmp->next;
	// lst->next = tmp->next;
	// FREE(tmp->str);
	// FREE(tmp);

	// put_lst(lst);

	int fd1 = open("fdsa", O_RDONLY);
	int fd2 = open("test", O_RDONLY);
	// printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));


	return (0);
}
