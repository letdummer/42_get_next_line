#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>

 int	main(void)
{
	char	*line;
	const char	*filename[] = 
	{"tests/example.txt", "tests/long_text.txt", "tests/one_char.txt"};
	int	fd;
	int	i = 0;
	int	j = 0;

	while (i < 3)
	{
		fd = open(filename[i], O_RDONLY);
		if (fd < 0)
		{
			printf("Error opening file");
			return (-1);
		}
		printf("\n__________________________________");
		printf("\nFILENAME:\t%s\n", filename[i]);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf ("line[%d]:%s", j, line);
			free(line);
			j++;
		}
		close (fd);
		i++;
		j = 0;
	}
	return (0);
}

/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int	i = 1;
	int	j = 1;
	
	if (argc > 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
			{
				i++;
				printf("Error");
				return (1) ;
			}
			printf("\n__________________________________");
			printf("\nFILENAME:\t%s\n", argv[i]);
			while ((line = get_next_line(fd)) != NULL)
			{
				printf("line[%d]:%s", j, line);
				free(line);
				j++;
			}
			close(fd);
			i++;
			j = 1;
		}
	}
	return (0);
}

*/
