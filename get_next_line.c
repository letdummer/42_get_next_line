#include "get_next_line.h"

char  *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	printf(" insidre get_next_line function\n");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (!buffer)
		buffer = (char *)ft_calloc(1, sizeof(char));
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL); 
	
	line = extract_line(buffer);
	printf("extracting line\n");
	buffer = clean_buffer(buffer);
	printf("finish\n");
	if (!line)
		return (free(buffer), NULL);
	return (line);
}

char	*read_file(int fd, char *tmp)
{
	char	*buffer;
	char	*new_buffer;
	int		bytes;

	printf("insidre read_file function\n");

	
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <0)
		{
			free(buffer);
			free (tmp);
			return (NULL);
		}
		buffer[bytes] = '\0';
		new_buffer = ft_strjoin(tmp, buffer);
		if (!new_buffer)
			return (free(tmp), NULL);
		free(tmp);
		tmp = new_buffer;
	}
	free(buffer);
	return (tmp);
}

char	*extract_line(char *tmp)
{
	int 	i;
	int 	j;
	char	*line;


	printf("inside exrtact_line function\n");

	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\0')
		line = ft_calloc(i + 1, sizeof(char));
	else
		line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	if (!line)
		return (NULL);
	
	i = -1;
	while (tmp[++i] && tmp[i] != '\n')
	{
		line[j++] = tmp[i];
	}
	if (tmp[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);	
}

char	*clean_buffer(char *tmp)
{
	int 	i;
	int 	j;
	char	*new_tmp;


	printf("inside clean_buffer function\n");

	i = 0;
	j = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
	{
		i++;
	}
	
	if(tmp[i] == '\0')
	{
		free(tmp);
		return (NULL);
	} 

	printf("imalloc\n");
	new_tmp = malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	i++;

	while (tmp[i] != '\0')
	{
		new_tmp[j] = tmp[i];
		j++;
		i++;
		// VERIFICAR SE AS POSICOES ESTAOS CORRETAS OU SE TEM Q ENVAR O [I] !!
	}
	new_tmp[j] = '\0';
	free(tmp);
	return (new_tmp);
}
