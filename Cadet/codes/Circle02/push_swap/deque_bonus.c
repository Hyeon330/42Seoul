/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:23:19 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/05 07:54:40 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	add_head(t_deque *dq, int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->prev = NULL;
	new->num = num;
	if (dq->size == 0)
		dq->tail = new;
	else
		dq->head->prev = new;
	new->next = dq->head;
	dq->head = new;
	dq->size++;
}

void	add_tail(t_deque *dq, int num)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->next = NULL;
	new->num = num;
	if (dq->size == 0)
		dq->head = new;
	else
		dq->tail->next = new;
	new->prev = dq->tail;
	dq->tail = new;
	dq->size++;
}

int	poll_head(t_deque *dq)
{
	t_node	*tmp;
	int		num;

	tmp = dq->head;
	num = tmp->num;
	dq->head = tmp->next;
	free(tmp);
	if (dq->head)
		dq->head->prev = NULL;
	dq->size--;
	return (num);
}

int	poll_tail(t_deque *dq)
{
	t_node	*tmp;
	int		num;

	tmp = dq->tail;
	num = tmp->num;
	dq->tail = tmp->prev;
	free(tmp);
	if (dq->tail)
		dq->tail->next = NULL;
	dq->size--;
	return (num);
}
