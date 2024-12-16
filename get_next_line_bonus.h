/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekashirs <ekashirs@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:08:53 by ekashirs          #+#    #+#             */
/*   Updated: 2024/12/16 14:42:47 by ekashirs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t number, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int search);
void	ft_extract_line(char **buffer, char **line, size_t len);
void	ft_read_line(char **buffer, int fd);

#endif
