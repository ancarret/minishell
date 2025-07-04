/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:24:27 by ancarret          #+#    #+#             */
/*   Updated: 2025/04/03 18:11:43 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer[fd])
			free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = read_to_buffer(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = get_line_buffer(&buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}

char	*get_line_buffer(char **buffer)
{
	int		i;
	char	*aux;
	char	*line;

	if (!*buffer || **buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = ft_substr(*buffer, 0, i + 1);
	if (!line)
		return (NULL);
	if ((*buffer)[i])
		aux = ft_substr(*buffer, i + 1, ft_strlen(*buffer) - i);
	else
		aux = NULL;
	free(*buffer);
	*buffer = aux;
	return (line);
}

char	*read_to_buffer(char *buffer, int fd)
{
	char	*temp_buffer;
	int		read_bytes;

	temp_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buffer)
	{
		free(buffer);
		return (NULL);
	}
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		if (!process_read(&read_bytes, temp_buffer, &buffer, fd))
		{
			free(temp_buffer);
			return (NULL);
		}
	}
	free(temp_buffer);
	return (buffer);
}

int	process_read(int *read_bytes, char *temp_buffer, char **buffer, int fd)
{
	char	*aux;

	*read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
	if (*read_bytes == -1)
	{
		free(*buffer);
		return (0);
	}
	temp_buffer[*read_bytes] = '\0';
	aux = ft_strjoin(*buffer, temp_buffer);
	free(*buffer);
	if (!aux)
		return (0);
	*buffer = aux;
	return (1);
}

