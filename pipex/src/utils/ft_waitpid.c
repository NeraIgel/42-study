/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:48:20 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:31:28 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	ft_waitpid(pid_t pid, int options)
{
	int		stat;

	if (waitpid(pid, &stat, options) < 0)
	{
		perror("waitpid");
		return (EXIT_FAILURE);
	}
	if (WIFEXITED(stat))
		return (WEXITSTATUS(stat));
	else if (WIFSIGNALED(stat))
		return (WTERMSIG(stat));
	else
		return (EXIT_FAILURE);
}
