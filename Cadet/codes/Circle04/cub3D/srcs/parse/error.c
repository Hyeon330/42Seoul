/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:21:57 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/10/05 23:03:22 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	prs_err(unsigned int e_no)
{
	if (e_no >= E_CRITICAL)
		perror(NULL);
	if (e_no == PRS_DYNAMIC)
		write(2, "Dynamic allocation failed\n", 26);
	if (e_no == PRS_EXTENSION)
		write(2, "Extension error\n", 16);
	if (e_no == PRS_FORMAT)
		write(2, "Format error\n", 13);
	if (e_no == PRS_TEXTURE_PATH)
		write(2, "Invalid texture path\n", 21);
	exit(EXIT_FAILURE);
}
