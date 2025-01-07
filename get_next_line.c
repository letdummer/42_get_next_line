#include "get_next_line.h"

char  *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	printf("buffer: %s\n", buffer);

	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	printf("%s", buffer);
		
	line = extract_line(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}

static int	find_line(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


char	*read_file(int fd, char *tmp)
{
	ssize_t		bytes;
	char	*buffer;
	char	*new_buffer;


	printf("tmp: %s\n", tmp);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (find_line(tmp) == 0 && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		buffer[bytes] = '\0';
		new_buffer = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = new_buffer;
	}
	printf("\n\t\tREAD_FILE\n");
	free(buffer);
	return (tmp);
}

char	*extract_line(char *tmp)
{
	int 	i;
	char	*line;

	i = 0;
	if (!tmp || !*tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
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
	if (!tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	
	if(!tmp[i])
		return (free(tmp), NULL);

	new_tmp = ft_calloc((ft_strlen(tmp) - i), sizeof(char));
	if (!new_tmp)
		return (NULL);
	i++;
	while (tmp[i])
		new_tmp[j++] = tmp[i++];
	free(tmp);
	return (new_tmp);
}
