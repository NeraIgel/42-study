/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:33:35 by heha              #+#    #+#             */
/*   Updated: 2022/02/09 12:49:10 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static bool	ft_find_line(const char *s, char **line)
{
	char	*find;

	*line = NULL;
	if (s)
	{
		find = ft_strchr(s, '\n');
		if (find)
			*line = ft_strndup(s, find - s + 1);
	}
	return (*line != NULL);
}

static char	*ft_strappend(char *dst, char const *src)
{
	char	*new;
	char	*tmp;

	if (!dst)
	{
		tmp = ft_strndup("", 0);
		if (!tmp)
			return (NULL);
		dst = tmp;
	}
	new = dst;
	if (src)
	{
		new = ft_strjoin(dst, src);
		if (!new)
			return (NULL);
		free(dst);
	}
	return (new);
}

static char	*ft_cut_line(char *s, char **line, bool isEOF)
{
	char	*remain;
	size_t	str_len;
	size_t	line_len;

	remain = s;
	if (s)
	{
		str_len = ft_strlen(s);
		if (!(*line) && isEOF && str_len)
			*line = ft_strndup(s, str_len);
		if (*line)
		{
			line_len = ft_strlen(*line);
			remain = ft_strndup(s + line_len, str_len - line_len);
			if (!remain)
				return (NULL);
			free(s);
		}
	}
	return (remain);
}

static void	ft_gnlclear(char **buf, char **store, bool isEOF)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	if (*store && **store == '\0' && isEOF)
	{
		free(*store);
		*store = NULL;
	}
}

char	*get_next_line(int fd)
{
	char			*buf;
	ssize_t			rsize;
	char			*line;
	static char		*store;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_find_line(store, &line))
	{
		rsize = read(fd, buf, BUFFER_SIZE);
		if (rsize <= 0)
			break ;
		buf[rsize] = '\0';
		store = ft_strappend(store, buf);
		if (!store)
			break ;
	}
	store = ft_cut_line(store, &line, !rsize);
	ft_gnlclear(&buf, &store, !rsize);
	return (line);
}
