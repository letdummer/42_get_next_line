/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:35:47 by ldummer-          #+#    #+#             */
/*   Updated: 2025/01/08 15:02:23 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int i;
	
	i = 1;
	line = NULL;
	fd = open("tests/long_text.txt", O_RDONLY);
	printf("opening file\n");
	if (fd < 0)
	{
		printf("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("line[%d]: %s\n", i++, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
/* 
int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;

	int fd;
	char *line;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	
	line = get_next_line(fd);
	while (line)
	{
		printf("line: %s", line);
		free(line);
		line = get_next_line(fd);	
	}
	close (fd);
	return (0);
}
 */