#include "../header/minishell.h"

int test() {
    int i;
    int num_processes = 5; // 예제에서 생성할 자식 프로세스의 수
    
    for (i = 0; i < num_processes; i++) {
        pid_t pid = fork();
        
        if (pid == 0) {
            // 자식 프로세스가 할 일
            printf("자식 프로세스 %d 시작\n", getpid());
            sleep(i + 1); // 자식 프로세스마다 다른 시간 동안 대기
            printf("자식 프로세스 %d 종료\n", getpid());
            exit(123);
        } else if (pid < 0) {
            // fork() 호출 실패
            fprintf(stderr, "fork() 실패\n");
            return 1;
        }
    }
    
    // 각 자식 프로세스가 종료될 때까지 기다림
    int	status;
    pid_t child_pid;
    while ((child_pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("자식 프로세스 %d 정상 종료\n", child_pid);
        } else {
            printf("자식 프로세스 %d 비정상 종료\n", child_pid);
        }
		printf("pid: %d, status: %d\n", child_pid, status >> 8);
    }
    
    return 0;
}

int main(int ac, char **av, char **env)
{
	// char buf[1024];

	// getcwd(buf, sizeof(buf));
	// printf("%s\n", buf);

	// printf("%d\n", chdir("test"));

	// getcwd(buf, sizeof(buf));
	// printf("%s\n", buf);

	// char *av[2];

	// av[0] = "ls";
	// av[1] = NULL;
	// execve("/bin/ls", av, NULL);
	// t_cmd cmd;

	// ft_memset(&cmd ,0, sizeof(t_cmd));
	// cmd.av = (char **)malloc(sizeof(char *) * 3);
	// cmd.av[0] = "cd";
	// cmd.av[1] = "~";
	// cmd.av[2] = NULL;

	// pwd();
	// cd(&cmd);
	// pwd();

	// pid_t	pid;
	// int		chk;

	// pid = fork();
	// if (!pid)
	// {
	// 	if (execve("dsafda", NULL, NULL) == -1)
	// 		exit(127);
	// }
	// waitpid(pid, &chk, 0);
	// printf("%d\n", chk >> 8);

	test();
}

