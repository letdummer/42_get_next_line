#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"

// ________________________________________________


int	main(void)
{
	int		fd;
	char	*line;

	//line = NULL;
	fd = open("example.txt", O_RDONLY);
	printf("opening file\n");
	if (fd < 0)
	{
		printf("Error opening file");
		return 1; 
	}
	
	line = get_next_line(fd);
	while (line)
	{
		printf("line: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}



/* int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int fd;
	char *line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	
	line = get_next_line(fd);
	while (line)
	{
		printf("line: %s", line);
		free(line);
		line = get_next_line(fd);	
	}
	close (fd);
	return (0);
} */