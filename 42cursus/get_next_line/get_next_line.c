/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:22:43 by junseo            #+#    #+#             */
/*   Updated: 2021/12/04 23:34:15 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_line(int fd, char *buffer, char *backup)
{
	int			read_result;
	char		*line;

	while (ft_strchr(buffer, '\n') == NULL)
	{
		read_result = read(fd, buffer, BUFFER_SIZE);
		if (read_result == -1)
			return (NULL);
		else if (read_result == 0)
			break ;
		buffer[read_result] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	line = backup;
	return (line);
}

char	*extract(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	result = ft_strdup(line + i + 1);
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, backup);
	free(buffer);
	backup = extract(line);
	return (line);
}
