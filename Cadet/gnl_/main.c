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
#include <fcntl.h>

typedef struct s_lst {
	char			*str;
	struct s_lst	*next;
	struct s_lst	*before;
}	t_lst;

void	func1(t_lst **lst)
{
	*lst = (*lst)->next;
}

void	func2(t_lst **lst)
{
	printf("--%s\n", (*lst)->before->str);
	printf("--%s\n", (*lst)->next->str);
	/*(*lst)->before->next = (*lst)->next;
	FREE(tmp->str);
	FREE(tmp);*/
}

void	func(t_lst **lst)
{
	t_lst *tmp;

	tmp = *lst;
	func1(lst);
	printf("%s\n", (*lst)->str);
	printf("before->%p\n", (*lst)->before);
	printf("%s\n", (*lst)->next->str);
//	func2(lst);
	*lst = tmp;
	printf("%s\n", (*lst)->str);
}

int	main(void)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(lst));
	lst->before = NULL;
	lst->str = (char *)malloc(sizeof(char) * 3);
	lst->str[0] = 'h';
	lst->str[1] = 'e';
	lst->str[2] = 0;
	printf("-->%s\n", lst->str);
	lst->next = (t_lst *)malloc(sizeof(lst));
	lst->next->before = lst;
	printf("before->%p\n", lst);
	printf("before->%p\n", lst->next->before);
	lst->next->str = (char *)malloc(sizeof(char) * 3);
	lst->next->str[0] = 'w';
	lst->next->str[1] = 'o';
	lst->next->str[2] = 0;
	printf("-->%s\n", lst->next->str);
	lst->next->next = (t_lst *)malloc(sizeof(lst));
	printf("next-->%p\n", lst->next->next);
	lst->next->next->before = lst->next;
	lst->next->next->str = (char *)malloc(sizeof(char) * 3);
	lst->next->next->str[0] = 'i';
	lst->next->next->str[1] = 'j';
	lst->next->next->str[2] = 0;
	printf("-->%s\n", lst->next->next->str);
	lst->next->next->next = NULL;

	func(&lst);


	
	return (0);
}
