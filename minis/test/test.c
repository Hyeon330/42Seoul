#include "../header/minishell.h"

int main(void)
{
	// int fd[2];
	// char buff[30];

	// ft_memset(buff, 0, 30);
	// pipe(fd);

	// char *str = "hello\n";
	// while (*str)
	// 	write(fd[1], str++, 1);
	// str = "world";
	// while (*str)
	// 	write(fd[1], str++, 1);
	// str = "hahahaha";
	// while (*str)
	// 	write(fd[1], str++, 1);
	// close(fd[1]);
	// read(fd[0], buff, 30);
	// printf("%s\n", buff);
	char *str[3];

	str[0] = "cat";
	str[1] = "fdsa";
	str[2] = NULL;
	execve("/bin/cat", str, NULL);
}