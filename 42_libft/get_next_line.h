/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdos-s < lucdos-s@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:17:18 by lucdos-s          #+#    #+#             */
/*   Updated: 2022/07/20 19:30:48 by lucdos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char			*ft_strchr_new(const char *s, int c);
size_t			ft_strlen_new(const char *s);
char			*ft_strjoin_new(char *s1, char *s2);
char			*ft_strdup_new(const char *s);
char			*get_next_line(int fd);
char			*get_line(char *buffer, int fd);
char			*ft_cut(char *buffer);
char			*ft_memcpy_new(void *dest, char *src, size_t n);
char			*ft_join_line(char *line);
char			*ft_no_line_join(int fd, char *buffer);
void			*ft_memset_new(void *s, int c, size_t n);

#endif
