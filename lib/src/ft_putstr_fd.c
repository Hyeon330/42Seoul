/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:07:23 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/13 17:49:36 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	cnt;

	cnt = -1;
	while (s[++cnt])
		write(fd, s + cnt, 1);
	return (cnt);
}
