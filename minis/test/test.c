#include "../header/minishell.h"

int main(void)
{
	char buf[1024];

	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);

	printf("%d\n", chdir("test"));

	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);

	char *av[2];

	av[0] = "ls";
	av[1] = NULL;
	execve("/bin/ls", av, NULL);
}