#include "minishell.h"

void	signal_handler(int signum)
{
	if (signum != SIGINT)
		return ;
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

int main(int argc, char **argv, char **envp)
{
	//int		sig;
	char	*str;

	if (argc < 0 && argv == 0 && envp == 0)
		return (0);//테스트 위해서 넣어놓은 부분
	//signal(SIGINT, signal_handler);
	while (1)
	{
		str = readline("prompt : ");
		if (!str)
		{
			continue;
		}//문자가 들어오지 않고 시그널이 들어온 경우
		else if (str[0] == '\0')//빈 문자열이 들어온 경우
			free(str);
		else
		{
			add_history(str);
			tokenize_main(str);
			// token = parsing(str);
			// do_cmd(token);
			free(str);
		}
	}//종료조건? str이 null일때? eof일때 시그널에서 처리
	return (0);
}