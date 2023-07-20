#include "minishell.h"
#include "termios.h"

void	handler(int signum)
{
	if (signum == SIGINT)//ctrl + c가 들어올 때
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}//^C가 계속나옴;오ㅐ지?->시그널 설정해줌
	else
		return ;
}

void	signal_set(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);//^c꺼줌
	signal(SIGINT, handler); //ctrl + c 일때 handler함수 실행
	signal(SIGQUIT, SIG_IGN); //ctlr + \ 시그널 무시
}
//하고 메인문 아래처럼 고치기

/*
int	main(int ac, char **av, char **env)
{
	t_vars	vars;
	char	*str;

	(void)ac;
	(void)av;
	(void)env;
	str = NULL;
	vars_init();
	signal_set();
	// signal(SIGQUIT, handler);
	while (1)
	{
		str = readline(PROMPT);
		if (!str)
		{
			printf("exit");
			return (0);
		}
		if (str[0] == '\0')
		{
			free(str);
			continue ;
		}
		add_history(str);
		parse(&vars, str);
		exec(vars);
		free(str);
	}
}*/