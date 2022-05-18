/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:46:39 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:28:34 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "libft.h"
#include "ft_utils.h"

static void	ft_error(const char *errmsg, const char *file, int ret)
{
	if (errmsg && file)
	{
		ft_putstr_fd("\033[31;1mError: \033[0m", STDERR_FILENO);
		ft_putstr_fd((char *)file, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	else
		perror(errmsg);
	exit(ret);
}

static int	ft_open_read(const char *file)
{
	int		fd;

	if (access(file, F_OK) < 0)
		ft_error("no such file or directory", file, 3);
	if (access(file, R_OK) < 0)
		ft_error("permission denied", file, 5);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("open", NULL, 110);
	return (fd);
}

static int	ft_open_write(const char *file, int oflag)
{
	int		fd;

	if (!file[0])
		ft_error("no such file or directory", file, 3);
	if (access(file, F_OK) == 0 && access(file, W_OK) < 0)
		ft_error("permission denied", file, 5);
	fd = open(file, oflag, 0644);
	if (fd < 0)
		ft_error("open", NULL, 110);
	return (fd);
}

int	ft_open(const char *file, int flags)
{
	int		oflag;

	if (flags & OPEN_READ)
		return (ft_open_read(file));
	else
	{
		oflag = O_WRONLY | O_TRUNC | O_CREAT;
		if (flags & OPEN_WRITE_APPEND)
			oflag = O_WRONLY | O_APPEND | O_CREAT;
		return (ft_open_write(file, oflag));
	}
}
