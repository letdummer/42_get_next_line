#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*ft_strdup(const char *str1);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlen(const char *str);



#endif
