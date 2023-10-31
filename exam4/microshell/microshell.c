#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define STDIN_BACK 3
#define STDOUT_BACK 4
#define STDERR_BACK 5

typedef struct	s_cmd {
	struct s_cmd	*next;
	char			**av;
	int				ac;
}	t_cmd;

typedef struct	s_token {
	t_cmd	*cmd;
	int		size;
}	t_token;

void	parse(int ac, char **av, t_token* token) {
	
}

int	chk_pipe_col(char* str, int *fd) {
	if (!strncmp(str, "|", 2)) {
		pipe(fd);
		return 1;
	}
	if (!strncmp(str, ";", 2))
		return 1;
	return 0;
}

int main(int ac, char **av, char **env) {
	t_cmd	cmd;
	pid_t	pid;
	int		fd[2];

	dup2(STDIN_BACK, STDIN_FILENO);
	dup2(STDOUT_BACK, STDOUT_FILENO);
	dup2(STDERR_BACK, STDERR_FILENO);
	while (*++av) {
		memset(&cmd, 0, sizeof(t_cmd));
		memset(fd, 0, sizeof(int) * 2);
		if (chk_pipe_col(*av, fd)) {
			if (!cmd.av)
				exit(EXIT_FAILURE);
			
			pid = fork();
			if (!pid) {
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				execve(cmd.av[0], cmd.av, env);
			}
			close(fd[1]);
			if (fd[0]);
				dup2(fd[0], STDIN_FILENO);
			free(cmd.av);
		} else {
			int	i = -1;

			cmd.ac = -1;
			while (av[++cmd.ac]) {
				if (!strncmp(av[cmd.ac], ";", 2) || !strncmp(av[cmd.ac], "|", 2))
					break;
			}
			cmd.av = (char **)malloc(sizeof(char *) * (cmd.ac + 1));
			cmd.av[cmd.ac] = NULL;
			while (++i < cmd.ac)
				cmd.av[i] = av[i];
			av += cmd.ac;
		}
	}
	wait(0);

	return 0;
}
