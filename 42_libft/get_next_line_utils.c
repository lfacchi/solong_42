/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:17:32 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/19 19:29:26 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset_new(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

char	*ft_strjoin_new(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*new_string;

	if (s1 == NULL || *s1 == '\0')
		return (ft_strdup_new(s2));
	new_string = malloc((ft_strlen_new(s1) + ft_strlen_new(s2)) + 1);
	i = 0;
	j = ft_strlen_new(s1);
	if (new_string == NULL)
		return (NULL);
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		new_string[j] = s2[i];
		j++;
		i++;
	}
	new_string[j] = '\0';
	return (new_string);
}

size_t	ft_strlen_new(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL || *s == '\0')
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_new(const char *s)
{
	int		i;
	char	*strdup;
	size_t	j;

	j = ft_strlen_new(s);
	if (s == NULL)
		return (NULL);
	i = 0;
	strdup = malloc((j * sizeof(char)) + 1);
	if (strdup == NULL)
		return (NULL);
	while (s[i])
	{
		strdup[i] = s[i];
		i++;
	}
	strdup[i] = '\0';
	return (strdup);
}

char	*ft_memcpy_new(void *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
