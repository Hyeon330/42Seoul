/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsul <hyeonsul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:14:53 by hyeonsul          #+#    #+#             */
/*   Updated: 2023/05/28 12:11:27 by hyeonsul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(t_cmd *cmd)
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
	return (0);
}

int	cd(t_cmd *cmd, t_tree *env)
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
		// 	return(ft_error());
		cmd->av[1] = before;
	}
	if (chdir(cmd->av[1]) < 0)
		return (ft_error(SYSTEM));
	insert(env, "OLDPWD", search(env->root, "PWD"));
	insert(env, "PWD", cmd->av[1]);
	if (chk)
		printf("%s\n", cmd->av[1]);
	return (0);
}

int	pwd(t_env *root)
{
	printf("%s\n", search(root, "PWD"));
	return (0);
}

void	print_export(t_env *node)
{
	printf("declare -x %s", node->key);
	if (node->val)
		printf("=\"%s\"", node->val);
	printf("\n");
}

int	export(t_cmd *cmd, t_tree *env)
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
			return (ft_error(DYNAMIC));
		insert(env, tmp[0], ft_strchr(cmd->av[i], '=') + 1);
		j = 0;
		while (tmp[++j])
			free(tmp[j]);
		free(tmp);
	}
	return (0);
}

int	unset(t_cmd *cmd, t_tree *env)
{
	int	i;

	i = 0;
	while (cmd->av[++i])
		delete_(env, cmd->av[i]);
	return (0);
}

void	print_env(t_env *node)
{
	if (node->val)
		printf("%s=%s\n", node->key, node->val);
}

int	env(t_env **envp)
{
	inorder(*envp, print_env, ENV);
	return (0);
}

int	builtin(int builtin_no, t_cmd *cmd, t_tree *envp)
{
	if (builtin_no == ECHO)
		return (echo(cmd));
	if (builtin_no == CD)
		return (cd(cmd, envp));
	if (builtin_no == PWD)
		return (pwd(envp->root));
	if (builtin_no == EXPORT)
		return (export(cmd, envp));
	if (builtin_no == UNSET)
		return (unset(cmd, envp));
	if (builtin_no == ENV);
		return (env(envp));
	return (1);
}
