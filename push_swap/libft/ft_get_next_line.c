/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:07:13 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 11:27:37 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_gnl_init(char **store)
{
	*store = ft_strndup("", 0);
	return (*store != NULL);
}

static char	*ft_gnl_read(char **store, char *buf, ssize_t *rsize, int fd)
{
	char	*find;
	char	*new;

	while (true)
	{
		find = ft_strchr(*store, '\n');
		if (find)
			return (ft_strndup(*store, find - *store + 1));
		else
		{
			*rsize = read(fd, buf, BUFFER_SIZE);
			if (*rsize <= 0)
				return (NULL);
			buf[*rsize] = '\0';
			new = ft_strjoin(*store, buf);
			if (!new)
				return (NULL);
			free(*store);
			*store = new;
		}
	}
}

static char	*ft_gnl_update(char *store, char **line, ssize_t rsize)
{
	char	*remain;
	size_t	str_len;
	size_t	line_len;

	if (store)
	{
		str_len = ft_strlen(store);
		if (!(*line) && !rsize && str_len)
			*line = ft_strndup(store, str_len);
		if (*line)
		{
			line_len = ft_strlen(*line);
			remain = ft_strndup(store + line_len, str_len - line_len);
			if (!remain)
				return (NULL);
			free(store);
			return (remain);
		}
		if (*store == '\0' && rsize <= 0)
		{
			free(store);
			return (NULL);
		}
	}
	return (store);
}

char	*ft_get_next_line(int fd)
{
	char		*buf;
	ssize_t		rsize;
	char		*line;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!store && !ft_gnl_init(&store))
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_gnl_read(&store, buf, &rsize, fd);
	store = ft_gnl_update(store, &line, rsize);
	free(buf);
	return (line);
}
