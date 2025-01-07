#include "get_next_line.h"

char  *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = read_file(fd, buffer);
	printf("%s", buffer);
	if (!buffer)
		return (NULL);
		
	line = extract_line(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}

char	*read_file(int fd, char *tmp)
{
	int		bytes;
	char	*buffer;

	bytes = 1;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return ( NULL);
	while (!(ft_strchr(tmp, '\n')) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(tmp), NULL);
		buffer[bytes] = 0;
		tmp = ft_strjoin(tmp, buffer);
	}
	free(buffer);
	return (tmp);
}

char	*extract_line(char *tmp)
{
	int 	i;
	char	*line;

	i = 0;
	if (!tmp || tmp[0] == '\0')
		return (NULL);
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}


char	*clean_buffer(char *tmp)
{
	int 	i;
	int 	j;
	char	*new_tmp;


	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	
	/* if(!tmp[i])
		return (free(tmp), NULL); */

	new_tmp = ft_calloc((ft_strlen(tmp) - i + 1), sizeof(char));
	if (!new_tmp)
		return (free(tmp), NULL);
	i++;
	while (tmp[i])
		new_tmp[j++] = tmp[i++];
	free(tmp);
	return (new_tmp);
}
