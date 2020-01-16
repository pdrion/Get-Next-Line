/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:17:41 by pdrion            #+#    #+#             */
/*   Updated: 2020/01/15 19:15:13 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	newline(char **str, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_substr(*str, 0, len);
		tmp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_del(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_del(str);
	}
	return (1);
}

static int	ret(char **str, char **line, int cursor, int fd)
{
	if (cursor < 0)
		return (-1);
	else if (cursor == 0 && str[fd] == NULL)
		return (0);
	else
		return (newline(&str[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	char		data[BUFFER_SIZE + 1];
	static char	*str[FOPEN_MAX];
	int			cursor;
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((cursor = read(fd, data, BUFFER_SIZE)) > 0)
	{
		data[cursor] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(data);
		else
		{
			tmp = ft_strjoin(str[fd], data);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (ret(str, line, cursor, fd));
}
