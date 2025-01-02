#include "get_next_line.h"

# include <unistd.h>

char  *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}

char	*read_file(int fd, char *tmp)
{
	char	*buffer;
	int		bytes;
	
	if (!tmp)
		return (ft_calloc(1, 1));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = 0;
		if (!buffer)
			return (NULL);
		tmp = ft_strjoin(tmp, buffer);
	}
	free(buffer);
	return (tmp);
}

char	*extract_line(char *tmp)
{
	int 	i;
	char	*line;

	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] && tmp[i] == '\n')
		line[i++] = '\n';
	return (line);	
}

char	*clean_buffer(char *tmp)
{
	int i;
	char	*new_tmp;

	i = 0;
	while(tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	new_tmp = ft_calloc((ft_strlen(tmp) - i + 1), sizeof(char));
	i++;
	while(tmp[i] != '\0')
	{
		new_tmp = ft_strdup(tmp);
		// VERIFICAR SE AS POSICOES ESTAOS CORRETAS OU SE TEM Q ENVAR O [I] !!
	}
	new_tmp = '\0';
	free(tmp);
	return (new_tmp);
}
