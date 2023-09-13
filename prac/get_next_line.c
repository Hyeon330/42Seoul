#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *get_next_line(int fd)
{
	char *str = malloc(50000);
	char *copy = str;

	while (read(fd, copy, 1) > 0 && *copy++ != '\n');
	return (copy > str) ? (*copy = 0, str) : (free(str), NULL);
}

int main()
{
	printf("%s", get_next_line(0));
	printf("%s", get_next_line(0));
	printf("%s", get_next_line(0));
	printf("%s", get_next_line(0));
}
