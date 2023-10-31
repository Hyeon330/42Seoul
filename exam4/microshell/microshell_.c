#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define STDIN_BACK 3
#define STDOUT_BACK 4
#define STDERR_BACK 5

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

int	cnt_av(char** av, t_token* token) {
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
	i = -1;
	while (av[++i]) {
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

		memset(tail, 0, sizeof(t_cmd));
		tail->ac = cnt_av(av + i, token);
		tail->av = (char**)malloc(sizeof(char*) * (tail->ac + 1));
		tail->av[tail->ac] = NULL;
		set_av(av + i, tail);
		token->size++;
		i += tail->ac;
	}
	return i;
}

int main(int ac, char** av, char** env) {
	t_token	token;

	++av;
	while (*av) {
		memset(&token, 0, sizeof(t_token));
		token.env = env;
		av += parse(av, env, &token);
		printf("%d\n", token.size);
		// if (token.size)
		// 	exec(token);
		if (!strncmp(*av, ";", 2))
			av++;
	}
}
