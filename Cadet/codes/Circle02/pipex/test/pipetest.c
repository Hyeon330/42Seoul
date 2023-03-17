#include "../header/pipex.h"

void func()
{
	char *str;
	char buff[3][BUFF_SIZE];
	int	pipefd[2];
	int	fd;

	ft_memset(buff, 0, BUFF_SIZE * 3);
	fd = open("aaa", O_RDONLY);
	read(fd, buff[0], BUFF_SIZE);
	str = "hello\nworld\nhahaha\n";

	pipe(pipefd);
	// write(pipefd[1], str, ft_strlen(str));
	write(pipefd[1], buff[0], ft_strlen(buff[0]));
	read(pipefd[0], buff[1], BUFF_SIZE);

	write(pipefd[1], buff[1], ft_strlen(buff[1]));
	read(pipefd[0], buff[2], BUFF_SIZE);


	printf("%s", buff[2]);
}

void func2()
{
	char *str;
	char buff[BUFF_SIZE];
	int fd[2];
	int cnt;
	pid_t pid;

	ft_memset(buff, 0, BUFF_SIZE);
	str = "hello\nworld\nhahaha\n";

	pipe(fd);
	write(fd[1], str, ft_strlen(str));

	cnt = 0;
	pid = fork();
	if (!pid)
	{
		cnt = read(fd[0], buff, BUFF_SIZE);
	}
	else
	{
		cnt = read(fd[0], buff, BUFF_SIZE);
	}
	printf("%d\n", cnt);
}

// 1. 읽기전용 파일디스크립터는 클로즈 됬을 경우 다시 읽으면 -1을 반환
// 2. 클로즈를 하지 않을 경우 파이프의 0번이나 그냥 0의 경우 무한 입력 대기상태
// 3. 파일을 연 fd의 경우 그냥 0을 반환
void func3()
{
	int fd[2];
	char *str = "hello\n";
	char buff[BUFF_SIZE];
	int file;

	file = open("aaa", O_RDONLY);

	pipe(fd);

	write(fd[1], str, ft_strlen(str));
	int a = read(fd[0], buff, BUFF_SIZE);
	printf("%d\n", a);

	printf("-----------------\n");

	close(fd[0]);
	int b = read(fd[0], buff, BUFF_SIZE);
	printf("%d\n", b);

	int c = read(file, buff, BUFF_SIZE);
	printf("%d\n", c);
	c = read(file, buff, BUFF_SIZE);
	printf("%d\n", c);
}

void func3()
{
	int fd[2];
	char *str = "hello\n";
	char buff[BUFF_SIZE];
	int file;

	file = open("aaa", O_RDONLY);

	pipe(fd);

	close(fd[1]);
	write(fd[1], str, ft_strlen(str));
	
}

int main()
{

}