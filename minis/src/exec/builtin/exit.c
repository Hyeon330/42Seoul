/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 05:30:29 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/08/02 17:45:28 by hyeonsul         ###   ########.fr       */
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
	int			sign;
	int			i;
	const int	max_loop = 18;

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
	i = -1;
	while (++i < max_loop && *str >= '0' && *str <= '9')
		*code = *code * 10 + (*str++ - '0') * sign;
	if (*str >= '0' && ((sign > 0 && *str <= '7') || (sign < 0 && *str <= '8')))
		*code = *code * 10 + (*str++ - '0') * sign;
	if (*str)
		return (0);
	return (1);
}

int	exit_clear(t_vars *vars, t_cmd *cmd)
{
	unsigned char	exit_code;

	if (vars->token.size <= 1)
		ft_putstr_fd("exit\n", STDERR_FILENO);
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
	}
	if (cmd)
		clear_token(&vars->token);
	clear_env(vars->env.root);
	rl_clear_history();
	exit(exit_code);
}
