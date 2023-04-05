/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:55:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/04/05 22:46:05 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>

# define BUFF_SIZE 1500 // 1296
# define BLOCK_HEIGHT 40
# define BLOCK_WIDTH 40

enum e_err {
	ARGUMENT = 0,
	DYNAMIC,
	FORMAT,
	OPEN = 32
};

typedef struct s_vars {
	void    *mlx;
	void    *win;
	char	**map;
	int		x_width;
	int		x_height;
	int		count_C;
}   t_vars;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_queue {
	int	queue[BUFF_SIZE];
	int	size;
	int	front;
	int	rear;
}	t_queue;

// checker.c
int		chk_map(t_vars *vars, t_img *bg);

// bfs.c
int		bfs(t_vars *vars, t_img *bg, int x, int y);

// queue.c
void	init_queue(t_queue *queue);
void	enqueue(t_queue *queue, int val);
int		dequeue(t_queue *queue);

// free_two_ptr.c
void	free_two_ptr_int(int **ptr, size_t size);
void	free_two_ptr_char(char **ptr);

// error.c
void	ft_error(int errno);

// libft.a
int		ft_printf(const char *format, ...);
void    *ft_memset(void *b, int c, size_t len);
char    **ft_split(char const *s, char c);
void    *ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);

#endif
