/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 23:14:32 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/15 03:45:15 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*str;
	t_cmd	**cmds;

	(void)ac;
	(void)av;
	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
			ft_error(DYNAMIC);
		if (!ft_strncmp(str, "exit", 5))
			break ;
		else
			exec(cmds, 0, env);
		add_history(str);
		free(str);
	}
	free(str);
}