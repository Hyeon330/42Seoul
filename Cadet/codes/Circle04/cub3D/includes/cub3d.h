/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:00:05 by hoseoson          #+#    #+#             */
/*   Updated: 2023/10/06 02:13:55 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h>

# define K_ESC 53
# define K_AR_L 123
# define K_AR_R 124
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2

# define MAX_HEIGHT 100
# define MAX_WIDTH 100

# define TEXWIDTH 64
# define TEXHEIGHT 64

# define SCREENWIDTH 640
# define SCREENHEIGHT 480

# define PLANE 0.66
# define ROTATE 5.001
# define MOVE 0.30007

# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_ray
{
	t_img	img;
	t_img	texture[4];
	char	map[MAX_HEIGHT][MAX_WIDTH];
	int		ceiling_color;
	int		floor_color;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		texnum;
	double	wallx;
	int		tex_x;
	int		tex_y;
	double	step;
	double	texpos;
	int		x;
	void	*mlx;
	void	*win;
}	t_ray;

// ==================== exec ============================

// util
void	error(char *msg);
double	ft_abs(double x);
int		close_win(void);

// run
int		key(int keycode, t_ray *data);
int		raycasting(t_ray *data);

// move
void	key_a(t_ray *data);
void	key_d(t_ray *data);
void	key_w(t_ray *data);
void	key_s(t_ray *data);

// rotate
void	key_right(t_ray *data);
void	key_left(t_ray *data);

// raycasting
void	sidedist(t_ray *data);
void	dda(t_ray *data);
void	line_height(t_ray *data);
void	wall_color(t_ray *data);
void	draw_wall(t_ray *data);

// ==================== parse ============================

enum e_err_type {
	E_CUSTOM = 0,
	E_CRITICAL = 32
};

enum e_parse_err {
	PRS_DYNAMIC = E_CUSTOM,
	PRS_EXTENSION,
	PRS_FORMAT,
	PRS_TEXTURE_PATH,
	PRS_OPEN = E_CRITICAL
};

// parse.c
void	parse(t_ray *data, char *file);

// setter
void	set_id(t_ray *data, char *line);
void	set_map(t_ray *data, int fd, char *line);

// checker.c
void	chk_extension(char *file);
void	chk_id(t_ray *data);
void	chk_map(t_ray *data);

// parse_util.c
void	free_ppc(char **ppc);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		get_color_code(char **codes);

// parse_error
void	prs_err(unsigned int e_no);

#endif
