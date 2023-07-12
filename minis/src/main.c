/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:40:28 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/12 19:48:32 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_vars(t_vars *vars, char **p_env)
{
	ft_memset(vars, 0, sizeof(t_vars));
	set_env(&vars->env, p_env);
	std_inout_backup();
}

int	main(int ac, char **av, char **env)
{
	t_vars	vars;
	char	*str;

	(void)ac;
	(void)av;
	init_vars(&vars, env);
	while (1)
	{
		str = readline(PROMPT);
		if (!str)
			break ;
		if (*str)
		{
			add_history(str);
			parse(&vars, str);
			exec(&vars);
			clear_token(&vars.token);
		}
		free(str);
	}
	free(str);
	clear_env(vars.env.root);
	return (0);
}
