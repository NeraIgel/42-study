/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_setup_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:18:42 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 11:40:16 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_utils.h"
#include "ft_graphic_bonus.h"

static void	ft_tblclear(char ***tbl)
{
	char	**cp;

	if (*tbl)
	{
		cp = *tbl;
		while (*cp)
		{
			free(*cp);
			cp++;
		}
		free(*tbl);
		*tbl = NULL;
	}
}

static bool	ft_queue_push_pos(t_queue *q, int y, int x, const char *s)
{
	t_pos	pos;
	char	*endptr;

	pos.x = x;
	pos.y = y;
	pos.z = ft_strtoi(s, &endptr, 10);
	if (s == endptr)
		return (ft_graphic_error(NULL, ERR_MAP_FORMAT));
	pos.color = 0xb3b3b3;
	if (',' == *endptr)
	{
		s = endptr + 1;
		pos.color = ft_strtoi(s, &endptr, 16);
		if (s == endptr)
			return (ft_graphic_error(NULL, ERR_MAP_FORMAT));
	}
	ft_queue_push(q, &pos, sizeof(t_pos));
	return (true);
}

static bool	ft_queue_push_tbl(t_queue *q, int *row, int *col, char *const *tbl)
{
	int		x;

	x = 0;
	while (tbl[x])
	{
		if (!ft_queue_push_pos(q, *row, x, tbl[x]))
			return (ft_graphic_error(NULL, NULL));
		x++;
	}
	if (x == 0)
		return (ft_graphic_error(NULL, ERR_ROW_EMPTY));
	if (*col == 0)
		*col = x;
	if (*col != x)
		return (ft_graphic_error(NULL, ERR_MAP_WIDTH));
	(*row)++;
	return (true);
}

static bool	ft_queue_save_data(t_queue *q, int *row, int *col, int fd)
{
	int		ret;
	char	*line;
	char	**tbl;

	*row = 0;
	*col = 0;
	while (1)
	{
		ret = ft_gnl_without_newline(fd, &line);
		if (ret <= 0)
			break ;
		tbl = ft_split(line, ' ');
		free(line);
		if (!tbl)
			return (ft_graphic_error(NULL, ERR_MALLOC));
		ret = ft_queue_push_tbl(q, row, col, tbl);
		ft_tblclear(&tbl);
		if (!ret)
			return (ft_graphic_error(NULL, NULL));
	}
	if (ret < 0)
		return (ft_graphic_error(NULL, ERR_FILE_READ));
	if (ft_queue_empty(q))
		return (ft_graphic_error(NULL, ERR_FILE_EMPTY));
	return (true);
}

bool	ft_graphic_setup(t_graphic *g, const char *file)
{
	int		fd;
	bool	ret;
	size_t	len;
	int		row;
	t_queue	queue;

	len = 0;
	if (file)
		len = ft_strlen(file);
	if (len < 5 || ft_strncmp(file + len - 4, ".fdf", 4))
		return (ft_graphic_error(NULL, ERR_FILE_NAME));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_graphic_error(NULL, ERR_FILE_OPEN));
	ft_queue_init(&queue);
	ret = ft_queue_save_data(&queue, &row, &(g->col), fd);
	close(fd);
	if (ret)
		ret = ft_graphic_save_data(g, row, &queue);
	ft_queue_clear(&queue);
	return (ret);
}
