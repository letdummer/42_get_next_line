#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"

/* int main(void)
{
  int   fd;
  //int   count = 0;
  char  *next_line;

  fd = open("example.txt", O_RDONLY);
  //fd = open("../tests/empty.txt", O_RDONLY);
  //fd = open("../tests/long_text.txt", O_RDONLY);
  //fd = open("../tests/newline_terminator.txt", O_RDONLY);
  //fd = open("../tests/one_char.txt", O_RDONLY);

  next_line = get_next_line(fd);
  while (next_line != NULL)
	{
		printf("%s", next_line);
		printf("[testing]");
		free(next_line);
		next_line = get_next_line(fd);
	}
	//

  close(fd);
  return (0);
} */


// ________________________________________________


int	main(void)
{
	char	*line;
	int		fd;

	fd = open("example.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file");
		return 1; 
	}

	
  //  printf("opening document\n");
    //printf("__________________________\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line: %s", line);
		free(line);
		line = get_next_line(fd);
	}
  //  printf("__________________________\n");
    //printf("out the loop\n");
	close(fd);
	return (0);
}




/* 
int	main()
{
	int	fd = open("example.txt", O_RDONLY);
	char	*line;
	
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf ("%s", line);
		free(line);
	}
    printf("out the loop\n");
	close (fd);
	return (0);
} */