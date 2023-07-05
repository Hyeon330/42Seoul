/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:40:28 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/05 15:25:18 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_vars	vars;
	char	*str;

	(void)ac;
	(void)av;
	(void)env;
	str = NULL;
	vars_init();
	while (1)
	{
		str = readline(PROMPT);
		if (!str)
			return (0);
		add_history(str);
		parse(vars, str);
		exec(vars);
		free(str);
	}
}
