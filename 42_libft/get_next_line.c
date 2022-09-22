/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:17:01 by  lucdos-s         #+#    #+#             */
/*   Updated: 2022/07/19 19:23:22 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*aux;

	if (fd < 0 || fd > 255 || BUFFER_SIZE < 0)
		return (NULL);
	aux = ft_no_line_join(fd, buffer);
	line = ft_join_line(aux);
	buffer = ft_cut(aux);
	if (line != aux)
		free(aux);
	if (ft_strlen_new(line) == 0 && buffer == NULL)
	{
		free(line);
		free(buffer);
		return (NULL);
	}
	return (line);
}

char	*ft_strchr_new(const char *s, int c)
{
	int		i;
	size_t	len_s;

	len_s = ft_strlen_new(s);
	i = 0;
	if (s == NULL)
		return (NULL);
	if ((unsigned char)c == '\0')
		return ((char *)(s + len_s));
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_no_line_join(int fd, char *buffer)
{
	char	*aux_buffer;
	int		nbytes;
	char	*temp;

	if (!buffer)
		buffer = ft_strdup_new("");
	nbytes = 1;
	aux_buffer = malloc((BUFFER_SIZE + 1));
	ft_memset_new(aux_buffer, 0, (BUFFER_SIZE + 1));
	while (!ft_strchr_new(aux_buffer, '\n') && nbytes != 0)
	{
		nbytes = read(fd, aux_buffer, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free(buffer);
			free(aux_buffer);
			return (NULL);
		}
		aux_buffer[nbytes] = '\0';
		temp = buffer;
		buffer = ft_strjoin_new(buffer, aux_buffer);
		free(temp);
	}
	free(aux_buffer);
	return (buffer);
}

char	*ft_cut(char *buffer)
{
	char	*nbuffer;
	char	*temp;

	if (!buffer)
		return (NULL);
	temp = ft_strchr_new(buffer, '\n');
	if (temp == NULL)
		return (NULL);
	nbuffer = malloc(sizeof(char) * (ft_strlen_new(temp + 1) + 1));
	nbuffer = ft_memcpy_new(nbuffer, (temp + 1), ft_strlen_new(temp + 1));
	nbuffer[ft_strlen_new(temp + 1)] = '\0';
	if (*buffer == '\0')
		return (NULL);
	return (nbuffer);
}

char	*ft_join_line(char *line)
{
	char	*temp;
	int		pos;

	pos = 0;
	temp = ft_strchr_new(line, '\n');
	if (temp == NULL)
		pos = (int)ft_strlen_new(line);
	else
	{
		while (line[pos])
		{
			if (line[pos] == '\n')
				break ;
			pos++;
		}
	}
	if (ft_strchr_new(line, '\n'))
	{
		temp = (char *)malloc(sizeof(char) * (pos + 2));
		temp = ft_memcpy_new(temp, line, (pos + 1));
		temp[pos + 1] = '\0';
		return (temp);
	}
	else
		return (line);
}
