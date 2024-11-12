#include <stdio.h>
#include <fcntl.h>
#include "../includes/get_next_line.h"

int main()
{
	char *next_line = "";
	int	fd = 0;

	fd = open("txt.test", O_RDONLY);
	if (fd < 0)
	{
		printf("FAIL OPEN FILES\n");
		return (1);
	}
	while(1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			break;
		printf("%s", next_line);
		free(next_line);
	}
	close(fd);
	return (0);
}
