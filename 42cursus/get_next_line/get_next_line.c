/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junseo <junseo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:22:43 by junseo            #+#    #+#             */
/*   Updated: 2021/12/12 17:31:12 by junseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buf, char *backup)
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
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		if (!backup)
			return (NULL);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
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
		ret = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_line(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
