/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:02:22 by heha              #+#    #+#             */
/*   Updated: 2022/02/10 12:08:22 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*ft_gnl_getnode(t_list *head, int fd)
{
	char	*store;
	t_list	*node;
	t_list	*new;

	node = head->next;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	store = ft_strndup("", 0);
	if (!store)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->store = store;
	new->prev = head;
	new->next = head->next;
	if (head->next)
		(head->next)->prev = new;
	head->next = new;
	return (new);
}

static void	ft_gnl_delnode(t_list **node)
{
	t_list	*prev;
	t_list	*next;

	prev = (*node)->prev;
	next = (*node)->next;
	if ((*node)->store == NULL)
	{
		prev->next = next;
		if (next)
			next->prev = prev;
		free(*node);
		*node = NULL;
	}
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

char	*get_next_line(int fd)
{
	char			*buf;
	ssize_t			rsize;
	char			*line;
	t_list			*node;
	static t_list	head;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	node = ft_gnl_getnode(&head, fd);
	if (!node)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_gnl_read(&(node->store), buf, &rsize, fd);
	node->store = ft_gnl_update(node->store, &line, rsize);
	ft_gnl_delnode(&node);
	free(buf);
	buf = NULL;
	return (line);
}
