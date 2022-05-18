/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:41:45 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:22:55 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_error(const char *errmsg, int ret)
{
	perror(errmsg);
	exit(ret);
}

void	ft_dup2(int oldfd, int newfd)
{
	int		fd;

	if (oldfd != newfd)
	{
		fd = dup2(oldfd, newfd);
		close(oldfd);
		if (fd < 0)
			ft_error("dup2", EXIT_FAILURE);
	}
}
