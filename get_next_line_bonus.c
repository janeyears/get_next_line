/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:42:40 by ekashirs          #+#    #+#             */
/*   Updated: 2024/12/16 14:42:43 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, sizeof (char));
	if (!buffer[fd])
		return (NULL);
	if (!ft_strchr(buffer[fd], '\n'))
		ft_read_line(&buffer[fd], fd);
	if (!buffer[fd] || !*buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	len = 0;
	while (buffer[fd][len] != '\n' && buffer[fd][len] != '\0')
		len++;
	line = NULL;
	ft_extract_line(&buffer[fd], &line, len);
	return (line);
}
