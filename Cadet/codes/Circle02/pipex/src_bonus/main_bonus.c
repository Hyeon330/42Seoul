/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:06:13 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/03/25 16:30:06 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

void	init_args(t_args *args, int ac, char **av, char **env)
{
	args->ac = ac;
	args->av = av;
	args->env = env;
	args->here_doc = !ft_strncmp("here_doc", av[1], ft_strlen(av[1]));
}

int	main(int ac, char **av, char **env)
{
	t_args	args;
	int		fd[2];
	int		i;

	if (ac < 5)
		ft_error("The number of argument is wrong\n");
	init_args(&args, ac, av, env);
	set_first_in(args);
	i = 1 + args.here_doc;
	while (++i < ac - 1)
	{
		child_proc(fd, args, i);
		if (i < ac - 2)
			dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	if (args.here_doc)
		unlink(".here_doc");
	while (wait(0) != -1)
		;
}
