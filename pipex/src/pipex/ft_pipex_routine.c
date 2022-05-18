/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:01:58 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:18:54 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include "ft_pipex.h"
#include "ft_process.h"
#include "ft_utils.h"

static void	ft_pipex_head_child(int prev_pipe, int pipefd[], t_pipex *p, int i)
{
	close(pipefd[0]);
	if (i == 0)
		prev_pipe = ft_open(p->infile, OPEN_READ);
	ft_process_exec(p->command[i], p->environ, prev_pipe, pipefd[1]);
}

static void	ft_pipex_head_parent(int *prev_pipe, int pipefd[], pid_t pid, int i)
{
	close(pipefd[1]);
	if (i != 0)
		close(*prev_pipe);
	*prev_pipe = pipefd[0];
	ft_waitpid(pid, WNOHANG);
}

static void	ft_pipex_head_process(t_pipex *p)
{
	int		i;
	pid_t	pid;
	int		pipefd[2];
	int		prev_pipe;
	int		last_pipe;

	i = -1;
	while (++i < p->size - 1)
	{
		pid = ft_process_create(pipefd);
		if (pid < 0)
			ft_pipex_error(p, NULL);
		if (pid == 0)
			ft_pipex_head_child(prev_pipe, pipefd, p, i);
		ft_pipex_head_parent(&prev_pipe, pipefd, pid, i);
	}
	last_pipe = ft_open(p->outfile, OPEN_WRITE_TRUNC);
	ft_process_exec(p->command[i], p->environ, prev_pipe, last_pipe);
}

void	ft_pipex_routine(t_pipex *p)
{
	pid_t	pid;

	pid = ft_process_create(NULL);
	if (pid < 0)
		ft_pipex_error(p, NULL);
	if (pid == 0)
		ft_pipex_head_process(p);
	p->ret = ft_waitpid(pid, 0);
}
