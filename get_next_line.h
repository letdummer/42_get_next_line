#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h>

#include <unistd.h>	//COMENTAR
#include <stdio.h> //COMENTAR


# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_file(int fd, char *tmp);
char	*extract_line(char *tmp);
char	*clean_buffer(char *tmp);



char	*ft_strdup(const char *str1);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);



#endif
