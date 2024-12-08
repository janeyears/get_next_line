/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:08:16 by ekashirs          #+#    #+#             */
/*   Updated: 2024/12/03 15:43:26 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buffer;
	char	*line;
	size_t	len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_calloc(1, sizeof (char));
	if (buffer == NULL)
		return (NULL);
	if (!ft_strchr(buffer, '\n'))
		ft_read_line(&buffer, fd);
	if (buffer == NULL || *buffer == NULL)
	{
    	free(buffer);
    	buffer = NULL;
    	return (NULL);
	}
	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	line = NULL;
	ft_extract_line(&buffer, &line, len);
	return (line);
}
