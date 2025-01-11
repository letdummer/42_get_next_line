/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:35:42 by ldummer-          #+#    #+#             */
/*   Updated: 2025/01/11 12:34:18 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h> //for read function

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif

// main functions
char	*get_next_line(int fd);
char	*read_file(int fd, char *tmp);
char	*extract_line(char *tmp);
char	*clean_buffer(char *tmp);

// utility functions

char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str1);
int		find_line(char *buffer);

#endif
