/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:46:51 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/10 13:52:10 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	viewer(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->element.wall.img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
	if (vars->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->element.collectible.img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
	if (vars->map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->element.exit_o.img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
	if (vars->map[i][j] == 'E' && vars->count_c)
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->element.exit_c.img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
	if (vars->map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->element.player_l.img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
	if (vars->map[i][j] == 'P' && vars->lnr)
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->element.player_r.img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
}

void	view(t_vars *vars)
{
	int		i;
	int		j;

	mlx_put_image_to_window(vars->mlx, vars->win, vars->element.back.img, 0, 0);
	i = -1;
	while (++i < vars->x_height)
	{
		j = -1;
		while (++j < vars->x_width)
			viewer(vars, i, j);
	}
}
