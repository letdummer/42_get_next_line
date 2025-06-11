/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldummer- <ldummer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:35:33 by ldummer-          #+#    #+#             */
/*   Updated: 2025/06/11 09:41:15 by ldummer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Helper function that joins two strings
// Returns the new string
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*new_str;
	size_t		i;
	size_t		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = (char *)malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (new_str == NULL)
		return (free(new_str), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// Helper function that allocates memory and initializes it to zero
void	*ft_calloc_gnl(size_t nitems, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nitems * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (nitems * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

// Helper function that calculates the length of a string
size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Helper function that duplicates a string
// Returns the new string
char	*ft_strdup_gnl(const char *str1)
{
	char	*new_string;
	size_t	i;

	new_string = (char *) malloc (ft_strlen_gnl(str1) + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		new_string[i] = str1[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
