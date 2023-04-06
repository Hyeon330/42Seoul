/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 03:23:26 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/06 22:21:20 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	set_map(char *mapname, t_vars *vars)
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
	return (chk_map1(vars));
}

void	set_img(t_vars *vars, t_img *img, char *texture_path)
{
	img->img = mlx_xpm_file_to_image(vars->mlx, texture_path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	set_textures(t_vars *vars, t_img *element)
{
	set_img(vars, &element[1], "textures/wall.xpm");
	set_img(vars, &element[2], "textures/collectible.xpm");
	set_img(vars, &element[3], "textures/exit_c.xpm");
	set_img(vars, &element[4], "textures/exit_o.xpm");
	set_img(vars, &element[5], "textures/player_r.xpm");
	set_img(vars, &element[6], "textures/player_l.xpm");
}

// void	clear_img(t_img *element)
// {
	
// }

void	view(t_vars *vars)
{
	t_img	element[7];
	int	i;
	int	j;

	element[0].img = mlx_new_image(vars->mlx, BLOCK_WIDTH, BLOCK_HEIGHT);
	element[0].addr = mlx_get_data_addr(element[0].img, &element[0].bits_per_pixel, &element[0].line_length, &element[0].endian);
	i = -1;
	while (++i < BLOCK_HEIGHT)
	{
		j = -1;
		while (++j < BLOCK_WIDTH)
			my_mlx_pixel_put(&element[0], j, i, SPACE_COLOR);
	}
	set_textures(vars, element);
	i = -1;
	while (++i < vars->x_height)
	{
		j = -1;
		while (++j < vars->x_width)
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, element[1].img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, element[2].img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
			if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, element[3].img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
			if (vars->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, element[5].img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
		}
	}
}

int	key_press(int keycode, t_vars *vars)
{
	ft_printf("%d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (2 != ac)
		ft_error(ARGUMENT);
	vars.mlx = mlx_init();
	if (!set_map(av[1], &vars) || !chk_map2(&vars))
		ft_error(FORMAT);

	vars.win = mlx_new_window(vars.mlx, vars.x_width * BLOCK_WIDTH, \
		vars.x_height * BLOCK_HEIGHT, "so_long");

	fill_background();
	view(&vars);
	// mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
	
	mlx_loop(vars.mlx);
}
