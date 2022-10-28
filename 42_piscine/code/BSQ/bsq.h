/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:04:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2022/10/20 12:26:04 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_info
{
	int		row;
	int		col;
	int		**dp;
	char	**map;
	char	*buf;
	char	info[3];
	int		coords[3];
}	t_info;

// size.c
int		max_y_len(t_info *tif, int *i);
int		max_x_len(t_info *tif, int i);

// make_malloc.c
int		**make_2p_int_memory(int x, int y);
char	**make_2p_char_memory(int x, int y);

// fill.c
void	fill_map(char **map, char *buf, int index);
//void	fill_dp(char **map, int **dp, char *map_info, int *coords);
void	fill_dp(t_info *tif);

// bsq.c
void	solution(t_info tif, int index);
void	ft_putstr(char *str);

// get_real_info.c
int		get_real_info_file(t_info *tif, char *file, int *index);
void	get_real_info_input(t_info *tif, int *index);

// map_check.c
int		check_map(t_info *tif);

#endif
