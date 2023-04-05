/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 03:23:26 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/05 22:26:41 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_map(char *mapname, t_vars *vars, t_img *bg)
{
	int		fd;
	char	buff[BUFF_SIZE];

	ft_memset(buff, 0, BUFF_SIZE);
	fd = open(mapname, O_RDONLY);
	if (fd == -1 || read(fd, buff, BUFF_SIZE) == -1)
		ft_error(OPEN);
	vars->map = ft_split(buff, '\n');
	if (!vars->map)
		ft_error(DYNAMIC);
	vars->count_C = 0;
	bg->height = -1;
	while (vars->map[++bg->height])
	{
		bg->width = -1;
		while (vars->map[bg->height][++bg->width])
		{
			if (vars->map[bg->height][bg->width] == 'C')
				vars->count_C++;
		}
	}
	vars->x_height = bg->height * BLOCK_HEIGHT;
	vars->x_width = bg->width * BLOCK_WIDTH;
}

int main(int ac, char **av)
{
	t_vars	vars;
	t_img	bg;

	if (2 != ac)
		ft_error(ARGUMENT);
	// vars.mlx = mlx_init();
	set_map(av[1], &vars, &bg);
	if (!chk_map(&vars, &bg))
		ft_error(FORMAT);
	printf("good");
	// vars.win = mlx_new_window(vars.mlx, );

	// mlx_loop(vars.mlx);
}
