/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 03:23:26 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/12 21:03:58 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cls(t_vars *vars)
{
	size_t	i;

	i = -1;
	while (vars->map[++i])
		free(vars->map[i]);
	free(vars->map);
	free(vars->element.wall.img);
	free(vars->element.collectible.img);
	free(vars->element.exit_c.img);
	free(vars->element.exit_o.img);
	free(vars->element.player_r.img);
	free(vars->element.player_l.img);
	exit(EXIT_SUCCESS);
	return (0);
}

void	move(t_vars *vars, int *direct)
{
	vars->map[vars->y][vars->x] = '0';
	vars->map[direct[0]][direct[1]] = 'P';
	vars->y = direct[0];
	vars->x = direct[1];
	ft_printf("%d\n", ++vars->move);
}

int	key_press(int keycode, t_vars *vars)
{
	int	ud[4];
	int	lr[4];
	int	tmp[2];

	init_directions(ud, lr);
	tmp[0] = vars->y + ud[keycode - 123];
	tmp[1] = vars->x + lr[keycode - 123];
	if (keycode >= 123 && keycode <= 126 && vars->map[tmp[0]][tmp[1]] != '1')
	{
		if (vars->map[tmp[0]][tmp[1]] == 'E' && !vars->count_c)
			cls(vars);
		if (vars->map[tmp[0]][tmp[1]] == '0')
			move(vars, tmp);
		if (vars->map[tmp[0]][tmp[1]] == 'C')
		{
			vars->count_c--;
			move(vars, tmp);
		}
		if (keycode == 123 || keycode == 124)
			vars->lnr = keycode == 124;
		view(vars);
	}
	if (keycode == 53)
		cls(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars		vars;

	if (2 != ac)
		ft_error(ARGUMENT);
	ft_memset(&vars, 0, sizeof(t_vars));
	vars.mlx = mlx_init();
	if (!set_map(av[1], &vars) || !chk_map2(&vars))
		ft_error(FORMAT);
	vars.win = mlx_new_window(vars.mlx, vars.x_width * BLOCK_WIDTH, \
		vars.x_height * BLOCK_HEIGHT, "so_long");
	vars.lnr = vars.x_width / 2 > vars.x;
	set_textures(&vars);
	view(&vars);
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_hook(vars.win, 17, 0, cls, &vars);
	mlx_loop(vars.mlx);
}
