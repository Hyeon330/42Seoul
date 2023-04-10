/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:55:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/10 21:40:25 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

# define BUFF_SIZE 1500 // 1296
# define BLOCK_WIDTH 40
# define BLOCK_HEIGHT 40
# define MAX_RESOL_WIDTH 1920
# define MAX_RESOL_HEIGHT 1080
# define SPACE_COLOR 0x002F2D36

enum e_err {
	ARGUMENT = 0,
	DYNAMIC,
	FORMAT,
	EXTENTION,
	OPEN = 32
};

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_element {
	t_img	back;
	t_img	wall;
	t_img	collectible;
	t_img	exit_c;
	t_img	exit_o;
	t_img	player_r;
	t_img	player_l;
}	t_element;

typedef struct s_vars {
	t_element	element;
	void		*mlx;
	void		*win;
	char		**map;
	int			x_width;
	int			x_height;
	int			x;
	int			y;
	int			count_c;
	int			move;
	int			lnr;
}	t_vars;

typedef struct s_queue {
	int	queue[BUFF_SIZE];
	int	size;
	int	front;
	int	rear;
}	t_queue;

// setting.c
int		set_map(char *mapname, t_vars *vars);
void	set_textures(t_vars *vars);

// viewer.c
void	view(t_vars *vars);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

// checker.c
int		chk_map1(t_vars *vars);
int		chk_map2(t_vars *vars);

// bfs.c
int		bfs(t_vars *vars, int x, int y);
void	init_directions(int *ud, int *lr);

// queue.c
void	init_queue(t_queue *queue);
void	enqueue(t_queue *queue, int val);
int		dequeue(t_queue *queue);

// error.c
void	ft_error(int errno);

// libft.a
int		ft_printf(const char *format, ...);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

#endif
