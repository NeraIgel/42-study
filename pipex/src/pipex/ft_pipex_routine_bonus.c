/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_routine_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:15:38 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 15:47:17 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include "ft_pipex_bonus.h"
#include "ft_file_bonus.h"
#include "ft_process.h"
#include "ft_utils.h"

static void	ft_pipex_head_child(int prev_pipe, int pipefd[], t_pipex *p, int i)
{
	close(pipefd[0]);
	if (i == 0)
		prev_pipe = ft_infile(p->infile, p->limiter, p->size, p->heredoc);
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
	last_pipe = ft_outfile(p->outfile, p->heredoc);
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
	if (p->heredoc && ft_unlink(PATH_HEREDOC) < 0)
		ft_pipex_error(p, NULL);
}
