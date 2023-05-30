/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:11:06 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/30 21:22:53 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int signum)
{
	(void) signum;
	rl_on_new_line();
    rl_redisplay();
	printf("  \n");
	rl_on_new_line();
	rl_replace_line("", 0);
    rl_redisplay();
}

int main()
{
	char *str;

	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
	while (1)
	{
		str = readline("minishell$ ");
		printf("%s\n", str);
		add_history(str);
		free(str);
	}
}
