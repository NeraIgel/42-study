/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:39:06 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 14:41:25 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_monitor_bonus.h"
#include "ft_utils_bonus.h"

static void	ft_monitor_sem_init(t_monitor *m)
{
	m->sem.print = SEM_FAILED;
	m->sem.forks = SEM_FAILED;
	m->sem.sim_stop = SEM_FAILED;
	m->sem.sim_start = SEM_FAILED;
	m->sem.full_eaten = SEM_FAILED;
}

void	ft_monitor_init(t_monitor *m)
{
	m->num = 0;
	m->ret = EXIT_SUCCESS;
	ft_monitor_sem_init(m);
	memset(&(m->info), 0, sizeof(t_monitor_info));
	memset(&(m->thread), 0, sizeof(t_monitor_thread));
	memset(&(m->process), 0, sizeof(t_monitor_process));
}

void	ft_monitor_error(t_monitor *m, const char *errmsg)
{
	if (errmsg)
	{
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	ft_monitor_destroy(m);
	exit(EXIT_FAILURE);
}
