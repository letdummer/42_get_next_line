#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"

// ________________________________________________


int	main(void)
{
	char	*line;
	int		fd;

	fd = open("example.txt", O_RDONLY);
	/* if (fd < 0)
	{
		printf("Error opening file");
		return 1; 
	} */
	
	printf(" opening file\n");
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