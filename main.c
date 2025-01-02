#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"

/* int main(void)
{
  int   fd;
  //int   count = 0;
  char  *next_line;

  //fd = open("../tests/empty.txt", O_RDONLY);
  fd = open("example.txt", O_RDONLY);
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

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	//int		fd2;
	//int		fd3;
	fd1 = open("tests/example.txt", O_RDONLY);
	//fd2 = open("tests/empty.txt", O_RDONLY);
	//fd1 = open("tests/long_text.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
    printf("__________\n");
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
/* 		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line); */
		i++;
    printf("\n");
	}
	close(fd1);
	//close(fd2);
	//close(fd3);
	return (0);
}