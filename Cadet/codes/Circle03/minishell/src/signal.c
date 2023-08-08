/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:04:23 by eoh               #+#    #+#             */
/*   Updated: 2023/08/08 10:57:22 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		g_exit_code = 1;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
	else
		return ;
}

void	set_origing(t_vars *vars)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &vars->org);
}

void	signal_set(t_vars *vars)
{
	tcgetattr(STDIN_FILENO, &vars->term);
	tcgetattr(STDIN_FILENO, &vars->org);
	vars->term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &vars->term);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
}
