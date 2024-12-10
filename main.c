#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"

int main(void)
{
  int   fd;
  int   count = 0;
  char  *next_line;

  fd = open("../tests/example.txt", O_RDONLY);

  next_line = get_next_line(fd);


  close(fd);
  return (0);
}