#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>

/*
void (*old_fun)(int);

void	sigint_handler(int signo)
{
	printf("Ctrl-c키를 누르셨죠?!\n");
	printf("또 누루시면 종료됩니다.\n");
	signal(SIGINT, old_fun);
}

int main(void)
{
	old_fun = signal(SIGINT, sigint_handler);
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}
}*/

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

int main(void)
{
	char	*str;
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);//^c꺼줌
	signal(SIGINT, handler); //ctrl + c 일때 handler함수 실행
	signal(SIGQUIT, SIG_IGN); //ctlr + \ 시그널 무시
	while (1)
	{
		str = readline("prompt:");
		if (!str)//ctrl+d가 들어올 때
		{
			printf("exit");
			return (0);
		}
		if (str[0] == '\0')//엔터만 칠때
		{
			free(str);
			continue;
		}
		add_history(str);
		// parse(&vars, str);
		// exec(vars);
		free(str);
	}
}

//my_laptop
//brew info readline
//-L/opt/homebrew/opt/readline/lib
//-I/opt/homebrew/opt/readline/include

//gcc test_signal.c -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include -lreadline