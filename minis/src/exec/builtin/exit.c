/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 05:30:29 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/20 18:39:46 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_exit_err {
	EXIT_TOO_MANY = 0,
	EXIT_NUM
};

static int	exit_error(int e_no, char *str)
{
	write(2, "minish: exit: ", 14);
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
	}
	if (e_no == EXIT_TOO_MANY)
		write(2, "too many arguments\n", 19);
	if (e_no == EXIT_NUM)
		write(2, "numeric argument required\n", 26);
	return (1);
}

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
		*code = *code * 10 + (*str++ - '0') * sign;
	if (*str)
		return (0);
	return (1);
}

int	exit_clear(t_vars *vars, t_cmd *cmd)
{
	unsigned char	exit_code;

	exit_code = 0;
	if (cmd && cmd->av[1])
	{
		if (!get_code(cmd->av[1], &exit_code))
		{
			exit_error(EXIT_NUM, cmd->av[1]);
			exit(255);
		}
		if (cmd->ac > 2)
			return (exit_error(EXIT_TOO_MANY, NULL));
		exit(exit_code);
	}
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (cmd)
		clear_token(&vars->token);
	clear_env(vars->env.root);
	exit(0);
}
