#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> //for read function

#include <stdio.h> //COMENTAR


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

// main functions
char	*get_next_line(int fd);
char	*read_file(int fd, char *tmp);
char	*extract_line(char *tmp);
char	*clean_buffer(char *tmp);

// utility functions

char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str1);



#endif
