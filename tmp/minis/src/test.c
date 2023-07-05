/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:11:06 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/06/02 03:27:05 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int signum)
{
	(void) signum;
	printf("\n");
	rl_on_new_line();
	// rl_replace_line("", 0);
    // rl_redisplay();
}

int main()
{
	char *str;

	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
			printf("%s\n", "hello");
		else
			printf("%s\n", str);
		add_history(str);
		free(str);
	}
}