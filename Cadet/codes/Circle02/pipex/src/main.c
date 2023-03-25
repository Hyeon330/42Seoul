/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:06:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/25 16:31:42 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init_args(t_args *args, int ac, char **av, char **env)
{
	args->ac = ac;
	args->av = av;
	args->env = env;
}

int	main(int ac, char **av, char **env)
{
	t_args	args;
	int		fd[2];
	int		i;

	if (ac != 5)
		ft_error("The number of argument is wrong\n");
	init_args(&args, ac, av, env);
	in_out(av[1], STDIN_FILENO);
	i = 1;
	while (++i < ac - 1)
	{
		child_proc(fd, args, i);
		if (i < ac - 2)
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	while (wait(0) != -1)
		;
}
