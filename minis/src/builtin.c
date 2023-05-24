/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:14:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/21 22:23:02 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_cmd *cmd)
{
	int	opt;
	int	i;
	
	opt = !ft_strncmp(cmd->av[1], "-n", 3);
	i = 0 | opt;
	while (++i < cmd->ac)
	{
		printf("%s", cmd->av[i]);
		if (i != cmd->ac - 1)
			printf(" ");
	}
	if (!opt)
		printf("\n");
}

void	cd(t_cmd *cmd, t_tree *env)
{
	char	*before;
	int		chk;

	if (cmd->av[2])
		ft_error(CHDIR_ARG);
	chk = !ft_strncmp(cmd->av[1], "-", 2);
	if (chk)
	{
		before = search(env->root, "OLDPWD");
		// if (!before)
		// {
			// ft_error();
		// 	return (0);
		// }
		cmd->av[1] = before;
	}
	if (!cmd->av[1] || !ft_strncmp(cmd->av[1], "~", 2))
		cmd->av[1] = search(env->root, "HOME");
	if (chdir(cmd->av[1]) < 0)
		ft_error(SYSTEM);
	insert(env, "OLDPWD", search(env->root, "PWD"));
	insert(env, "PWD", cmd->av[1]);
	if (chk)
		printf("%s\n", cmd->av[1]);
}

void	pwd()
{
	char	buf[PATH_LEN];

	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
}

void	print_export(t_env *node)
{
	printf("declare -x %s=\"%s\"\n", node->key, node->val);
}

void	export(t_cmd *cmd, t_tree *env)
{
	char	**tmp;
	int		i;
	int		j;

	if (!cmd->av[1])
		inorder(env->root, print_export, EXPORT);
	i = -1;
	while (cmd->av[++i])
	{
		tmp = ft_split(cmd->av[i], '=');
		if (!tmp)
			ft_error(DYNAMIC);
		insert(env, tmp[0], ft_strchr(cmd->av[i], '=') + 1);
		j = 0;
		while (tmp[++j])
			free(tmp[j]);
		free(tmp);
	}
}

void	unset(t_cmd *cmd, t_tree *env)
{
	int	i;

	i = 0;
	while (cmd->av[++i])
		delete_(env, cmd->av[i]);
}

void	print_env(t_env *node)
{
	printf("%s=%s\n", node->key, node->val);
}

void	env(t_env **envp)
{
	inorder(*envp, print_env, ENV);
}

void	builtin(int builtin_no, t_cmd *cmd, t_tree *envp)
{
	if (builtin_no == ECHO)
		echo(cmd);
	if (builtin_no == CD)
		cd(cmd, envp);
	if (builtin_no == PWD)
		pwd();
	if (builtin_no == EXPORT)
		export(cmd, envp);
	if (builtin_no == UNSET)
		unset(cmd, envp);
	if (builtin_no == ENV);
		env(envp);
}