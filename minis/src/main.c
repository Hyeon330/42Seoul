/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:40:28 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/26 21:21:51 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void	leaks_out()
//{
//	system("leaks minishell");
//}

void	init_vars(t_vars *vars, char **p_env)
{
	ft_memset(vars, 0, sizeof(t_vars));
	set_env(&vars->env, p_env);
	std_ioe_backup();
}

int	main(int ac, char **av, char **env)
{
	t_vars	vars;
	char	*str;

	//atexit(leaks_out);
	(void)ac;
	(void)av;
	init_vars(&vars, env);
	signal_set();
	while (1)
	{
		str = readline(PROMPT);
		if (!str)
			break ;
		if (*str)
		{
			add_history(str);
			if (parse(&vars, str) != 0)
			{
				exec(&vars);
				clear_token(&vars.token);
			}
		}
		free(str);
	}
	exit_clear(&vars, NULL);
	return (0);
}
