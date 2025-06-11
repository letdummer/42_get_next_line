/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:35:42 by ldummer-          #+#    #+#             */
/*   Updated: 2025/06/11 09:41:15 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h> //for read function

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// main functions
char	*get_next_line(int fd);
char	*read_file(int fd, char *tmp);
char	*extract_line(char *tmp);
char	*clean_buffer(char *tmp);

// utility functions

char	*ft_strjoin_gnl(char *s1, char *s2);
void	*ft_calloc_gnl(size_t nitems, size_t size);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strdup_gnl(const char *str1);
int		find_line(char *buffer);

#endif
