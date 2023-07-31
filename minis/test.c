#include "minishell.h"

void	handler(int signum)
{
	if (signum == SIGINT)//ctrl + c가 들어올 때
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
        ft_putstr_fd(PROMPT, STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}//^C가 계속나옴;오ㅐ지?->시그널 설정해줌
	else
		return ;
}

int main()
{
    char    *str;

    while (1)
    {
        signal(SIGQUIT, SIG_IGN);
        signal(SIGINT, handler);
        ft_putstr_fd(PROMPT, STDOUT_FILENO);
        str = get_next_line(STDIN_FILENO);
        add_history(str);
        printf("%s\n", str);
        free(str);
    }
}