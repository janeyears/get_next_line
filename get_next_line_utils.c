/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:08:34 by ekashirs          #+#    #+#             */
/*   Updated: 2024/12/02 14:08:35 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(const char *str, int search)
{
	while (*str != '\0')
	{
		if (*str == search)
			return ((char *)str);
		str++;
	}
	if (search == '\0')
		return ((char *)str);
	return (NULL);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t s1_len;
	size_t s2_len;
	size_t i;
	char *res;

	res = NULL;
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	res = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < s1_len)
		res[i++] = *s1++;
	while (i < s1_len + s2_len)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

void *ft_calloc(size_t number, size_t size)
{
	unsigned char *ptr;
	size_t bytes;
	size_t i;

	bytes = number * size;
	if (size == 0)
		return (NULL);
	if (size && ((bytes / size) != number))
		return (NULL);
	ptr = malloc(bytes);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < bytes)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

void ft_read_line(char **buffer, int fd)
{
	char *tmp_buff;
	char *tmp_line;
	int bytes;

	tmp_buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (tmp_buff == NULL)
		return;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, tmp_buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(tmp_buff);
			return ;
		}
		tmp_buff[bytes] = '\0';
		tmp_line = ft_strjoin(*buffer, tmp_buff);
		free(*buffer);
		*buffer = tmp_line;
		if (ft_strchr(tmp_buff, '\n'))
			break;
	}
	free(tmp_buff);
}

void ft_extract_line(char **buffer, char **line, size_t len)
{
	char *remaining_data;
	size_t i;

	*line = ft_calloc(len + 2, sizeof(char));
	if (!(*line))
		return;
	i = 0;
	while (i < len)
	{
		(*line)[i] = (*buffer)[i];
		i++;
	}
	if ((*buffer)[i] == '\n')
		(*line)[i++] = '\n';
	(*line)[i] = '\0';
	if ((*buffer)[i])
	{
		remaining_data = ft_strjoin(*buffer + i, "");
		free(*buffer);
		*buffer = remaining_data;
		return;
	}
	free(*buffer);
	*buffer = NULL;
}
