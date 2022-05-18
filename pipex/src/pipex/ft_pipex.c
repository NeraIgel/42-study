/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:53:24 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:16:32 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "libft.h"
#include "ft_pipex.h"

void	ft_pipex_init(t_pipex *p)
{
	p->ret = EXIT_SUCCESS;
	p->size = 0;
	p->infile = NULL;
	p->outfile = NULL;
	p->command = NULL;
	p->environ = NULL;
}

void	ft_pipex_clear(t_pipex *p)
{
	p->size = 0;
	p->infile = NULL;
	p->outfile = NULL;
	p->command = NULL;
	p->environ = NULL;
	waitpid(-1, NULL, 0);
}

void	ft_pipex_error(t_pipex *p, const char *errmsg)
{
	if (errmsg)
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	ft_pipex_clear(p);
	exit(EXIT_FAILURE);
}
