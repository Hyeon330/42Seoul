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

void	fill_background(t_vars *vars)
{
	t_img	back_img;
	int		height;
	int		width;
	int		i;
	int		j;

	height = vars->x_height * BLOCK_HEIGHT;
	width = vars->x_width * BLOCK_WIDTH;
	back_img.img = mlx_new_image(vars->mlx, BLOCK_WIDTH, BLOCK_HEIGHT);
	back_img.addr = mlx_get_data_addr(back_img.img, &back_img.bits_per_pixel, &back_img.line_length, &back_img.endian);
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			my_mlx_pixel_put(&back_img, j, i, SPACE_COLOR);
	}
	free(back_img.img);
	free(back_img.addr);
}

void	set_img(t_vars *vars, t_img *img, char *texture_path)
{
	img->img = mlx_xpm_file_to_image(vars->mlx, texture_path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	set_textures(t_vars *vars, t_img *element)
{
	set_img(vars, &element[0], "textures/wall.xpm");
	set_img(vars, &element[1], "textures/collectible.xpm");
	set_img(vars, &element[2], "textures/exit_c.xpm");
	set_img(vars, &element[3], "textures/exit_o.xpm");
	set_img(vars, &element[4], "textures/player_r.xpm");
	set_img(vars, &element[5], "textures/player_l.xpm");
}

void	clear_img(t_img *element)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		free(element[i].img);
		free(element[i].addr);
	}
}

void	view(t_vars *vars)
{
	t_img	element[6];
	int		i;
	int		j;

	fill_background(vars);
	set_textures(vars, element);
	i = -1;
	while (++i < vars->x_height)
	{
		j = -1;
		while (++j < vars->x_width)
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, element[0].img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, element[1].img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
			if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, element[2].img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
			if (vars->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, element[4].img, j * BLOCK_WIDTH, i * BLOCK_HEIGHT);
		}
	}
	clear_img(element);
}

int	key_press(int keycode, t_vars *vars)
{
	static int	move;

	if (keycode == 53)
		close(vars);
	return (0);
}

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
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
	mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
	mlx_hook(vars.win, 17, 1L<<0, close, &vars);
	
	mlx_loop(vars.mlx);
}
