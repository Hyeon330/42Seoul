/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 23:40:28 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/07/14 20:14:46 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_vars(t_vars *vars, char **p_env)
{
	ft_memset(vars, 0, sizeof(t_vars));
	set_env(&vars->env, p_env);
	std_ioe_backup();
}

void	test0(t_token *token)
{
	token->size = 1;
	token->cmd = (t_cmd *)malloc(sizeof(t_cmd) * token->size);
	
	token->cmd->next = NULL;
	token->cmd->red = NULL;

	token->cmd->ac = 1;
	token->cmd->av = (char **)malloc(sizeof(char *) * (token->cmd->ac + 1));
	token->cmd->av[0] = "ls";
	token->cmd->av[1] = NULL;
}

void	test1(t_token *token)
{
	token->size = 1;
	token->cmd = (t_cmd *)malloc(sizeof(t_cmd) * token->size);
	
	token->cmd->next = NULL;
	token->cmd->red = NULL;

	token->cmd->ac = 2;
	token->cmd->av = (char **)malloc(sizeof(char *) * (token->cmd->ac + 1));
	token->cmd->av[0] = "cat";
	token->cmd->av[1] = "tmp";
	token->cmd->av[2] = NULL;
}

void	test_exit(t_token *token)
{
	token->size = 1;
	token->cmd = (t_cmd *)malloc(sizeof(t_cmd) * token->size);
	
	token->cmd->next = NULL;
	token->cmd->red = NULL;

	token->cmd->ac = 1;
	token->cmd->av = (char **)malloc(sizeof(char *) * (token->cmd->ac + 1));
	token->cmd->av[0] = "exit";
	token->cmd->av[1] = NULL;
}

void	test(t_vars *vars, int i)
{
	if (i == 0)
		test0(&vars->token);
	if (i == 1)
		test1(&vars->token);
}

int	main(int ac, char **av, char **env)
{
	t_vars	vars;
	char	*str;
	int		i;

	(void)ac;
	(void)av;
	i = 0;
	init_vars(&vars, env);
	while (1)
	{
		str = readline(PROMPT);
		if (!str)
			break ;
		if (*str)
		{
			add_history(str);
			// parse(&vars, str);
			printf("%d\n", i);
			test(&vars, i++);
			exec(&vars);
			// clear_token(&vars.token);
		}
		free(str);
	}
	free(str);
	exit_clear(&vars, NULL);
	return (0);
}
