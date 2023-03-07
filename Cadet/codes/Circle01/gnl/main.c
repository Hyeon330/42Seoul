#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char	*get_next_line(int fd);

int main()
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		printf("%s", s);
		s = get_next_line(0);
	}
}
