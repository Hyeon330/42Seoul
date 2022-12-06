#include "get_next_line.h"
#include <fcntl.h>

void ft_strchar(char c)
{
	write(1, &c, 1);
}

int main()
{
	// int fd = open("abc.txt", O_WRONLY | O_CREAT, 0644);
	// char str[5] = "hello";
	// str[2] = 0;
	// write(fd, str, 5);
	// close(fd);

	// char buf[BUFF_SIZE];
	// fd = open("abc.txt", O_RDONLY);

	// int num;
	// num = read(fd, buf, BUFF_SIZE);
	// printf("num ==> %d\n", num);
	// for (int i = 0; i < num; i++)
	// {
	// 	if (buf[i] == 0)
	// 		write(1, "(null)", 6);
	// 	else
	// 		ft_strchar(buf[i]);
	// }

	int fd = open("abc", O_WRONLY | O_CREAT, 0644);
	char str[5] = "hello";
	str[2] = 0;
	write(fd, str, 5);
	close(fd);

	fd = open("abc", O_RDONLY);
	write(1, get_next_line(fd), 5);
	
	return 0;
}
