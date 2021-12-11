/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:22:43 by junseo            #+#    #+#             */
/*   Updated: 2021/12/11 18:15:57 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

static char	*read_line(int fd, char *buf, char **backup)
{
	int		cnt;
	char	*tmp;

	cnt = 1;
	while (cnt)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt == -1)
			return (0);
		else if (cnt == 0)
			break ;
		buf[cnt] = '\0';
		if (!backup[fd])
			backup[fd] = ft_strdup("");
		tmp = backup[fd];
		backup[fd] = ft_strjoin(tmp, buf);
		if (!backup[fd])
			return (NULL);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup[fd]);
}

static char	*extract(char *line)
{
	int		i;
	char	*ret;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	ret = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!ret)
		return (NULL);
	if (ret[0] == '\0')
	{
		free(ret);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	**backup;
	char		*line;
	char		*buffer;

	if (fd <= 0)
		return (NULL);
	backup = (char **)malloc(sizeof(char *) * _SC_OPEN_MAX);
	if (!backup)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, backup);
	free(buffer);
	backup[fd] = extract(line);
	return (line);
}

int	main(void)
{
	int fd = open("./testFile", O_RDONLY);

	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}
