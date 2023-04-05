/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 07:25:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/05 21:54:18 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_queue(t_queue *queue)
{
	ft_memset(queue->queue, 0, sizeof(int) * BUFF_SIZE);
	queue->size = 0;
	queue->front = -1;
	queue->rear = -1;
}

void	enqueue(t_queue *queue, int val)
{
	if (queue->size >= BUFF_SIZE)
		return ;
	++queue->size;
	queue->rear = (queue->rear + 1) % BUFF_SIZE;
	queue->queue[queue->rear] = val;
}

int	dequeue(t_queue *queue)
{
	if (queue->size == 0)
		return (0);
	--queue->size;
	queue->front = (queue->front + 1) % BUFF_SIZE;
	return queue->queue[queue->front];
}
