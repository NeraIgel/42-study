/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infile_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:30:00 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 17:32:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_utils.h"
#include "ft_file_bonus.h"

static void	ft_error(const char *errmsg, int ret)
{
	perror(errmsg);
	exit(ret);
}

static void	ft_put_prompt(int pipesize)
{
	int		i;

	i = 0;
	while (i < pipesize)
	{
		if (ft_putstr_fd("pipe ", STDOUT_FILENO) < 0)
			ft_error("write", EXIT_FAILURE);
		i++;
	}
	if (ft_putstr_fd("heredoc>", STDOUT_FILENO) < 0)
		ft_error("write", EXIT_FAILURE);
}

static int	ft_get_line(char **line)
{
	int		ret;

	ret = 0;
	while (!ret)
		ret = ft_get_next_line(STDIN_FILENO, line);
	return (ret);
}

static void	ft_heredoc(int fd, int pipesize, const char *limiter)
{
	char	*line;
	size_t	len;

	while (true)
	{
		ft_put_prompt(pipesize);
		if (ft_get_line(&line) < 0)
			ft_error("read", EXIT_FAILURE);
		len = 0;
		if (line)
			len = ft_strlen(line);
		if (len && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (line && !ft_strcmp(line, limiter))
		{
			free(line);
			break ;
		}
		if (line && ft_putendl_fd(line, fd) < 0)
		{
			free(line);
			ft_error("write", EXIT_FAILURE);
		}
		free(line);
	}
}

int	ft_infile(const char *infile, const char *limiter, int size, bool heredoc)
{
	int		fd;

	if (heredoc)
	{
		fd = ft_open(PATH_HEREDOC, OPEN_WRITE_TRUNC);
		ft_heredoc(fd, size - 1, limiter);
		close(fd);
		return (ft_open(PATH_HEREDOC, OPEN_READ));
	}
	else
		return (ft_open(infile, OPEN_READ));
}
