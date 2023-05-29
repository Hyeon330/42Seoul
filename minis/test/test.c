#include "../header/minishell.h"

// void	handle_signal(int signum)
// {
// 	(void) signum;
// 	printf("\n");
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
//     rl_redisplay();
// }

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

	// test();

	// char *str;

	// signal(SIGINT, handle_signal);
	// signal(SIGQUIT, handle_signal);
	// while (1)
	// {
	// 	str = readline("minishell$ ");
	// 	printf("%s\n", str);
	// 	add_history(str);
	// 	free(str);
	// }

	// char **av = {"", "world", NULL};
	// int i = execve("/bin/ps", NULL, NULL);
	printf("%d\n", strncmp(NULL, "hello", 6));

}

