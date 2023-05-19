#include "../header/minishell.h"

typedef struct s_list {
	int				num;
	struct s_list	*next;
}	t_list;

int main(int ac, char **av, char **env)
{
	// char buf[1024];

	// getcwd(buf, sizeof(buf));
	// printf("%s\n", buf);

	// printf("%d\n", chdir("test"));

	// getcwd(buf, sizeof(buf));
	// printf("%s\n", buf);

	// char *av[2];

	// av[0] = "ls";
	// av[1] = NULL;
	// execve("/bin/ls", av, NULL);
	// t_cmd cmd;

	// ft_memset(&cmd ,0, sizeof(t_cmd));
	// cmd.av = (char **)malloc(sizeof(char *) * 3);
	// cmd.av[0] = "cd";
	// cmd.av[1] = "~";
	// cmd.av[2] = NULL;

	// pwd();
	// cd(&cmd);
	// pwd();

	// pid_t	pid;
	// int		chk;

	// pid = fork();
	// if (!pid)
	// {
	// 	if (execve("dsafda", NULL, NULL) == -1)
	// 		exit(127);
	// }
	// waitpid(pid, &chk, 0);
	// printf("%d\n", chk >> 8);

	// (void)ac;
	// (void)av;

	// while (*env)
	// 	printf("%s\n", *env++);

	// printf("%d\n", ft_strncmp("hello", "hello", 6));

	t_list *lst;

	
}