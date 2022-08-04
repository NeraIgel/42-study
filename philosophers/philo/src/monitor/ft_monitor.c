/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:52:51 by heha              #+#    #+#             */
/*   Updated: 2022/07/27 13:22:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_monitor.h"
#include "ft_utils.h"

static void	ft_monitor_thread_destroy(t_monitor *m)
{
	int		i;
	void	*ret;

	i = 0;
	while (i < m->num)
	{
		if (m->thread.philos && m->thread.philos[i].initialized)
		{
			pthread_join(m->thread.philos[i].data, &ret);
			m->thread.philos[i].initialized = false;
			if (EXIT_SUCCESS != (int)ret)
				m->ret = EXIT_FAILURE;
		}
		i++;
	}
}

static void	ft_monitor_mutex_destroy(t_monitor *m)
{
	int		i;

	i = 0;
	while (i < m->num)
	{
		if (m->mutex.philos && m->mutex.philos[i].initialized)
		{
			pthread_mutex_destroy(&(m->mutex.philos[i].data));
			m->mutex.philos[i].initialized = false;
		}
		if (m->mutex.forks && m->mutex.forks[i].initialized)
		{
			pthread_mutex_destroy(&(m->mutex.forks[i].data));
			m->mutex.forks[i].initialized = false;
		}
		i++;
	}
	if (m->mutex.print.initialized)
		pthread_mutex_destroy(&(m->mutex.print.data));
	m->mutex.print.initialized = false;
	if (m->mutex.sim.initialized)
		pthread_mutex_destroy(&(m->mutex.sim.data));
	m->mutex.sim.initialized = false;
}

void	ft_monitor_init(t_monitor *m)
{
	m->num = 0;
	m->ret = EXIT_SUCCESS;
	memset(&(m->info), 0, sizeof(t_monitor_info));
	memset(&(m->time), 0, sizeof(t_monitor_time));
	memset(&(m->mutex), 0, sizeof(t_monitor_mutex));
	memset(&(m->shared), 0, sizeof(t_monitor_shared));
	memset(&(m->thread), 0, sizeof(t_monitor_thread));
	memset(&(m->property), 0, sizeof(t_monitor_property));
}

void	ft_monitor_destroy(t_monitor *m)
{
	if (m->mutex.sim.initialized)
		ft_set_monitor_simulation(\
				&(m->mutex.sim.data), &(m->property.sim), SIM_STOP);
	ft_monitor_thread_destroy(m);
	ft_monitor_mutex_destroy(m);
	free(m->thread.philos);
	free(m->shared.philos);
	free(m->mutex.philos);
	free(m->mutex.forks);
	m->thread.philos = NULL;
	m->shared.philos = NULL;
	m->mutex.philos = NULL;
	m->mutex.forks = NULL;
	m->num = 0;
}

bool	ft_monitor_error(t_monitor *m, const char *errmsg)
{
	if (errmsg)
	{
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	ft_monitor_destroy(m);
	m->ret = EXIT_FAILURE;
	return (false);
}
