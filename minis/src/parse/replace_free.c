#include "minishell.h"

void	free_replace_env(char *front, char *back, char *env)
{
	if (front)
		free(front);
	if (back)
		free(back);
	if (env)
		free(env);
}

void	free_replace_wave(char *temp, char *home, char *front, char *back)
{
	if (temp)
		free(temp);
	if (home)
		free(home);
	if (front)
		free(front);
	if (back)
		free(back);
}