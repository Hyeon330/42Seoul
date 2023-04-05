/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:13:12 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/05 22:45:05 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_directions(int *ud, int *lr)
{
	ud[0] = 1;
	ud[1] = 0;
	ud[2] = -1;
	ud[3] = 0;
	lr[0] = 0;
	lr[1] = 1;
	lr[2] = 0;
	lr[3] = -1;
}

void	enqueuer(t_vars *vars, t_queue *queue, int *now, int **flag)
{
	int	ud[4];
	int	lr[4];
	int	tmp[2];
	int	bg_len[2];
	int	i;

	init_directions(ud, lr);
	bg_len[0] = vars->x_height / BLOCK_HEIGHT;
	bg_len[1] = vars->x_width / BLOCK_WIDTH;
	i = -1;
	while (++i < 4)
	{
		tmp[0] = now[0] + ud[i];
		tmp[1] = now[1] + lr[i];
		if (tmp[0] >= 0 && tmp[0] < bg_len[0] && \
			tmp[1] >= 0 && tmp[1] < bg_len[1] && \
			!flag[tmp[0]][tmp[1]] && \
			vars->map[tmp[0]][tmp[1]] != '1')
		{
			enqueue(queue, tmp[0] * BUFF_SIZE + tmp[1]);
			flag[tmp[0]][tmp[1]] = 1;
		}
	}
}

int	bfs_loop(t_vars *vars, t_img *bg, t_queue *queue, int **flag)
{
	int	now[2];
	int	element[3];
	int	tmp;

	ft_memset(element, 0, sizeof(int) * 3);
	while (queue->size != 0)
	{
		tmp = dequeue(queue);
		now[0] = tmp / BUFF_SIZE;
		now[1] = tmp % BUFF_SIZE;
		if (now[0] == 0 || now[0] == bg->height - 1 || \
			now[1] == 0 || now[1] == bg->width - 1)
			return (0);
		if (vars->map[now[0]][now[1]] == 'P')
			element[0]++;
		if (vars->map[now[0]][now[1]] == 'C')
			element[1]++;
		if (vars->map[now[0]][now[1]] == 'E')
			element[2]++;
		enqueuer(vars, queue, now, flag);
	}
	if (element[0] != 1 || element[2] != 1 || element[1] != vars->count_C)
		return (0);
	return (1);
}

int	bfs(t_vars *vars, t_img *bg, int x, int y)
{
	t_queue	queue;
	int		**flag;
	int		i;
	int		ret;

	flag = ft_calloc(bg->height, sizeof(int *));
	if (!flag)
		ft_error(DYNAMIC);
	i = -1;
	while (++i < bg->height)
	{
		flag[i] = ft_calloc(bg->width, sizeof(int));
		if (!flag[i])
		{
			free_two_ptr_int(flag, i);
			ft_error(DYNAMIC);
		}
	}
	init_queue(&queue);
	enqueue(&queue, y * BUFF_SIZE + x);
	flag[y][x] = 1;
	ret = bfs_loop(vars, bg, &queue, flag);
	free_two_ptr_int(flag, bg->height);
	return (ret);
}
