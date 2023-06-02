#include "../header/minishell.h"

static int	get_code(char *str, unsigned char *code)
{
	int	sign;

	*code = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		*code =  *code * 10 + (*str++ - '0') * sign;
    if (*str)
        return (0);
	return (1);
}

int main(int ac, char **av, char **env)
{
	char path[1024];

	getcwd(path, 1024);
	printf("%s\n", path);
    printf("%d\n", chdir("/Users/hyeonsul"));
	getcwd(path, 1024);
	printf("%s\n", path);

	char *str[2];

	str[0] = "ls";
	str[1] = NULL;
	execve("/bin/ls", str, NULL);
}
