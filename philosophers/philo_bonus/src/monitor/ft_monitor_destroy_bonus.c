/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_destroy_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:03:19 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 18:00:56 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/wait.h>
#include "ft_monitor_bonus.h"
#include "ft_utils_bonus.h"

static void	ft_destroy_error(t_monitor *m, const char *errmsg)
{
	if (errmsg)
	{
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	m->ret = EXIT_FAILURE;
}

static void	ft_monitor_process_destroy(t_monitor *m)
{
	int		i;
	int		stat;

	if (m->process.philos)
	{
		i = -1;
		while (++i < m->num)
		{
			if (m->process.philos[i] > 0)
				if (kill(m->process.philos[i], SIGTERM) < 0)
					ft_destroy_error(m, "kill");
		}
		i = -1;
		while (++i < m->num)
		{
			if (m->process.philos[i] > 0)
			{
				if (waitpid(m->process.philos[i], &stat, 0) < 0)
					ft_destroy_error(m, "waitpid");
				else if (WIFEXITED(stat) && EXIT_SUCCESS != WEXITSTATUS(stat))
					m->ret = EXIT_FAILURE;
			}
		}
	}
}

static void	ft_monitor_thread_destroy(t_monitor *m)
{
	t_thrd	*thrd;
	void	*ret;

	thrd = &(m->thread.check_philos_full_eaten);
	if (thrd->initialized)
	{
		if (pthread_join(thrd->data, &ret) != 0)
			ft_destroy_error(m, "pthread_join");
		else if (EXIT_SUCCESS != (int)ret)
			m->ret = EXIT_FAILURE;
		thrd->initialized = false;
	}
}

static void	ft_monitor_sem_destroy(t_monitor *m)
{
	if (SEM_FAILED != m->sem.full_eaten && sem_close(m->sem.full_eaten) < 0)
		ft_destroy_error(m, "sem_close: full_eaten");
	if (SEM_FAILED != m->sem.sim_start && sem_close(m->sem.sim_start) < 0)
		ft_destroy_error(m, "sem_close: sim_start");
	if (SEM_FAILED != m->sem.sim_stop && sem_close(m->sem.sim_stop) < 0)
		ft_destroy_error(m, "sem_close: sim_stop");
	if (SEM_FAILED != m->sem.forks && sem_close(m->sem.forks) < 0)
		ft_destroy_error(m, "sem_close: forks");
	if (SEM_FAILED != m->sem.print && sem_close(m->sem.print) < 0)
		ft_destroy_error(m, "sem_close: print");
	m->sem.full_eaten = SEM_FAILED;
	m->sem.sim_start = SEM_FAILED;
	m->sem.sim_stop = SEM_FAILED;
	m->sem.forks = SEM_FAILED;
	m->sem.print = SEM_FAILED;
}

void	ft_monitor_destroy(t_monitor *m)
{
	ft_monitor_process_destroy(m);
	ft_monitor_thread_destroy(m);
	ft_monitor_sem_destroy(m);
	free(m->process.philos);
	m->process.philos = NULL;
	m->num = 0;
}
