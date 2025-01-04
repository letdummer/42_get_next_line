#include "get_next_line.h"

char  *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (!buffer)
		buffer = (char *)ft_calloc(1, sizeof(char));
	buffer = read_file(fd, buffer);

	if (!buffer)
		return (NULL); 
	
	line = extract_line(buffer);
	buffer = clean_buffer(buffer);
	if (!line)
		return (free(buffer), NULL);
	return (line);
}

char	*read_file(int fd, char *tmp)
{
	char	*buffer;
	//char	*new_buffer;
	ssize_t		bytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return ( NULL);
	bytes = 1;
	while (!ft_strchr(tmp, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(tmp), NULL);
		buffer[bytes] = '\0';
		if (!buffer)
			return (NULL);
		tmp = ft_strjoin(tmp, buffer);
		/* if (!new_buffer)
			return (free(tmp), NULL);
		free(tmp);
		tmp = new_buffer; */
	}
	free(buffer);
	return (tmp);
}

char	*extract_line(char *tmp)
{
	int 	i;
	int 	j;
	char	*line;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;

	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
	{
		line[j] = tmp[i];
		j++;
	}
	if (tmp[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
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
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	
	if(tmp[i] == '\0')
		return (free(tmp), NULL);

	new_tmp = ft_calloc(ft_strlen(tmp) - i + 1, sizeof(char));
	i++;
	if (!new_tmp)
		return (free(tmp), NULL);
	while (tmp[i] != '\0')
	{
		new_tmp[j] = tmp[i];
		j++;
		i++;
	}
	free(tmp);
	return (new_tmp);
}
