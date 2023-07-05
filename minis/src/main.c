/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:40:28 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/05 21:58:11 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	std_ioe_backup(void)
{
	dup2(STDIN_FILENO, STDIN_BACK);
	dup2(STDOUT_FILENO, STDOUT_BACK);
	dup2(STDERR_FILENO, STDERR_BACK);
}

void	vars_init(t_vars *vars, char **p_env)
{
	ft_memset(vars, 1, sizeof(t_vars));
	set_env(&vars->env, p_env);
	std_inout_backup();
}

int	main(int ac, char **av, char **env)
{
	t_vars	vars;
	char	*str;

	(void)ac;
	(void)av;
	vars_init(&vars, env);
	while (1)
	{
		str = readline(PROMPT);
		if (!str)
			return (0);
		add_history(str);
		parse(&vars, str);
		exec(&vars);
		free(str);
	}
}
