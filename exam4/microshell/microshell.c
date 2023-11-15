#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_cmd {
	struct s_cmd	*next;
	int				ac;
	char			**av;
}	t_cmd;

typedef struct	s_token {
	t_cmd	*cmd;
	char	**env;
	int		size;
}	t_token;

void	ft_memset(void* m, int v, int s) {
	char*	tmp;
	int		i;
	
	tmp = (char*)m;
	i = -1;
	while (++i < s)
		tmp[i] = v;
}

int	ft_strlen(char* str) {
	int	cnt;

	cnt = -1;
	while (str[++cnt]) ;
	return cnt;
}

int	cnt_av(char** av) {
	int i;

	i = -1;
	while (av[++i] && strncmp(av[i], ";", 2) && strncmp(av[i], "|", 2)) ;
	return i;
}

void	set_av(char** av, t_cmd* cmd) {
	int i;

	i = -1;
	while (++i < cmd->ac)
		cmd->av[i] = av[i];
}

int	parse(char** av, char** env, t_token* token) {
	t_cmd	*tail;
	int		i;

	tail = NULL;
	i = 0;
	while (av[i]) {
		if (!strncmp(av[i], ";", 2))
			break;
		if (!strncmp(av[i], "|", 2))
			i++;

		if (!tail) {
			token->cmd = (t_cmd*)malloc(sizeof(t_cmd));
			tail = token->cmd;
		} else {
			tail->next = (t_cmd*)malloc(sizeof(t_cmd));
			tail = tail->next;
		}

		ft_memset(tail, 0, sizeof(t_cmd));
		tail->ac = cnt_av(av + i);
		tail->av = (char**)malloc(sizeof(char*) * (tail->ac + 1));
		tail->av[tail->ac] = NULL;
		set_av(av + i, tail);
		token->size++;
		i += tail->ac;
	}
	token->env = env;
	return i;
}

char*	get_home(char** env) {
	while (*env) {
		if (!strncmp("HOME=", *env, 5))
			return *env + 5;
		env++;
	}
	return NULL;
}

void	cd(t_cmd* cmd) {
	if (cmd->ac != 2) {
		write(2, "error: cd: bad arguments\n", 25);
		return ;
	}
	if (chdir(cmd->av[1]) < 0)
		write(2, "error: cd: cannot change directory to path_to_change\n", 53);
}

void	exec(t_token *token) {
	t_cmd	*cmd;
	pid_t	pid;
	int		fd[2];
	int		i;

	cmd = token->cmd;
	if (!strncmp(cmd->av[0], "cd", 3)) {
		cd(cmd);
		return ;
	}
	i = -1;
	while (++i < token->size) {
		if (!cmd->ac)
			exit(EXIT_FAILURE);
		if (pipe(fd) < 0) {
			write(2, "error: fatal\n", 13);
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid < 0) {
			write(2, "error: fatal\n", 13);
			exit(EXIT_FAILURE);
		}
		if (!pid) {
			if (cmd->next)
				dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			if (execve(cmd->av[0], cmd->av, token->env) < 0) {
				write(2, "error: cannot execute ", 22);
				write(2, cmd->av[0], ft_strlen(cmd->av[0]));
				write(2, "\n", 1);
				exit(EXIT_FAILURE);
			}
		}
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		cmd = cmd->next;
	}
	waitpid(-1, NULL, 0);
}

int main(int ac, char** av, char** env) {
	t_token	token;

	(void)ac;
	++av;
	while (*av) {
		ft_memset(&token, 0, sizeof(t_token));
		token.env = env;

		av += parse(av, env, &token);
		if (token.size)
			exec(&token);
		if (*av && !strncmp(*av, ";", 2))
			av++;
	}
}
