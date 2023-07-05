/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 05:30:29 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 11:40:07 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_code(char *str, unsigned char *code)
{
	int	sign;

	*code = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		*code =  *code * 10 + (*str++ - '0') * sign;
    if (*str)
        return (0);
	return (1);
}

int	exit_clear(t_cmd *cmd, t_vars *vars)
{
	unsigned char	exit_code;
	int				chk_code;

	if (vars->cmds_cnt < 2)
		printf("%s\n", "exit");
	exit_code = 0;
	if (cmd && cmd->av[1])
	{
		chk_code = get_code(cmd->av[1], &exit_code);
		if (!chk_code)
		{
			exit_code = 255;
			exit_error(EXIT_NUM, cmd->av[1]);
		}
		if (chk_code && cmd->ac > 2)
			return (exit_error(EXIT_TOO_MANY, NULL));
	}
	if (vars->cmds_cnt < 2)
	{
		if (vars->cmds)
			free_cmds(vars);
		free_env(vars->env.root);
		exit(exit_code);
	}
	return (exit_code);
}