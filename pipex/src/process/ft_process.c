/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:33:43 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:20:18 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_utils.h"

pid_t	ft_process_create(int pipefd[])
{
	pid_t	pid;

	if (pipefd)
	{
		if (pipe(pipefd) < 0)
		{
			perror("pipe");
			return (-1);
		}
	}
	pid = fork();
	if (pid < 0)
	{
		if (pipefd)
		{
			close(pipefd[0]);
			close(pipefd[1]);
		}
		perror("fork");
	}
	return (pid);
}

void	ft_process_exec(const char *cmd, char *const envp[], int in, int out)
{
	ft_dup2(out, STDOUT_FILENO);
	ft_dup2(in, STDIN_FILENO);
	ft_execve(cmd, envp);
}
