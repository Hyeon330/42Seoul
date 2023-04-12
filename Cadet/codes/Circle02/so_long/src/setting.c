/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:42:26 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 12:27:09 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	set_map(char *mapname, t_vars *vars)
{
	int		fd;
	char	buff[BUFF_SIZE];
	char	*dot;

	ft_memset(buff, 0, BUFF_SIZE);
	dot = ft_strrchr(mapname, '.');
	if (ft_strncmp(dot, ".ber", 4))
		ft_error(EXTENTION);
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
	img->img = mlx_xpm_file_to_image(vars->mlx, texture_path, \
	&img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}

void	set_back(t_vars *vars)
{
	int		height;
	int		width;
	int		i;
	int		j;

	height = vars->x_height * BLOCK_HEIGHT;
	width = vars->x_width * BLOCK_WIDTH;
	vars->element.back.img = mlx_new_image(vars->mlx, width, height);
	vars->element.back.addr = mlx_get_data_addr(vars->element.back.img, \
	&vars->element.back.bits_per_pixel, &vars->element.back.line_length, \
	&vars->element.back.endian);
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			my_mlx_pixel_put(&vars->element.back, j, i, SPACE_COLOR);
	}
}

void	set_textures(t_vars *vars)
{
	set_back(vars);
	set_img(vars, &vars->element.wall, "textures/wall.xpm");
	set_img(vars, &vars->element.collectible, "textures/collectible.xpm");
	set_img(vars, &vars->element.exit_c, "textures/exit_c.xpm");
	set_img(vars, &vars->element.exit_o, "textures/exit_o.xpm");
	set_img(vars, &vars->element.player_r, "textures/player_r.xpm");
	set_img(vars, &vars->element.player_l, "textures/player_l.xpm");
}
