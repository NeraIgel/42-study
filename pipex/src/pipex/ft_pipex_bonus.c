/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:56:27 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:39:19 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "libft.h"
#include "ft_pipex_bonus.h"

void	ft_pipex_init(t_pipex *p)
{
	p->ret = EXIT_SUCCESS;
	p->size = 0;
	p->heredoc = false;
	p->limiter = NULL;
	p->infile = NULL;
	p->outfile = NULL;
	p->command = NULL;
	p->environ = NULL;
}

void	ft_pipex_clear(t_pipex *p)
{
	p->size = 0;
	p->heredoc = false;
	p->limiter = NULL;
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
