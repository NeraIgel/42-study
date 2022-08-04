/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:06:05 by heha              #+#    #+#             */
/*   Updated: 2022/07/29 15:56:43 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_monitor.h"
#include "ft_utils.h"

static bool	ft_monitor_alloc_setup(t_monitor *m)
{
	m->mutex.forks = ft_calloc(m->num, sizeof(t_mutex));
	if (NULL == m->mutex.forks)
		return (ft_monitor_error(m, "alloc"));
	m->mutex.philos = ft_calloc(m->num, sizeof(t_mutex));
	if (NULL == m->mutex.philos)
		return (ft_monitor_error(m, "alloc"));
	m->shared.philos = ft_calloc(m->num, sizeof(t_philo));
	if (NULL == m->shared.philos)
		return (ft_monitor_error(m, "alloc"));
	m->thread.philos = ft_calloc(m->num, sizeof(t_thread));
	if (NULL == m->thread.philos)
		return (ft_monitor_error(m, "alloc"));
	return (true);
}

static bool	ft_monitor_mutex_setup(t_monitor *m)
{
	int		i;

	i = 0;
	while (i < m->num)
	{
		if (pthread_mutex_init(&(m->mutex.philos[i].data), NULL) != 0)
			return (ft_monitor_error(m, "pthread_mutex_init"));
		m->mutex.philos[i].initialized = true;
		if (pthread_mutex_init(&(m->mutex.forks[i].data), NULL) != 0)
			return (ft_monitor_error(m, "pthread_mutex_init"));
		m->mutex.forks[i].initialized = true;
		i++;
	}
	if (pthread_mutex_init(&(m->mutex.print.data), NULL) != 0)
		return (ft_monitor_error(m, "pthread_mutex_init"));
	m->mutex.print.initialized = true;
	if (pthread_mutex_init(&(m->mutex.sim.data), NULL) != 0)
		return (ft_monitor_error(m, "pthread_mutex_init"));
	m->mutex.sim.initialized = true;
	return (true);
}

static void	ft_philo_shared_resources(t_philo *philo, t_monitor *m, int i)
{
	philo->id = i + 1;
	philo->info.time_to_die = m->info.time_to_die;
	philo->info.time_to_eat = m->info.time_to_eat;
	philo->info.time_to_sleep = m->info.time_to_sleep;
	philo->info.num_of_must_eat = m->info.num_of_must_eat;
	philo->time.even_wait = ft_max(m->num * 15, EVEN_PHILO_WAIT_TIME);
	philo->time.think_wait = PHILO_THINK_WAIT_TIME;
	philo->time.start_interval = PHILO_START_INTERVAL_TIME;
	philo->time.check_interval = ft_max(m->num * 5, PHILO_CHECK_INTERVAL_TIME);
	philo->mutex.sim = &(m->mutex.sim.data);
	philo->mutex.print = &(m->mutex.print.data);
	philo->mutex.self = &(m->mutex.philos[i].data);
	philo->mutex.fork1 = &(m->mutex.forks[i % m->num].data);
	philo->mutex.fork2 = &(m->mutex.forks[(i + 1) % m->num].data);
	philo->shared.sim = &(m->property.sim);
}

static bool	ft_monitor_thread_setup(t_monitor *m)
{
	int			i;
	t_philo		*philo;
	pthread_t	*pthread;

	i = 0;
	while (i < m->num)
	{
		philo = &m->shared.philos[i];
		ft_philo_shared_resources(philo, m, i);
		i++;
	}
	ft_set_monitor_simulation(\
			&(m->mutex.sim.data), &(m->property.sim), SIM_NONE);
	i = 0;
	while (i < m->num)
	{
		philo = &m->shared.philos[i];
		pthread = &(m->thread.philos[i].data);
		if (pthread_create(pthread, NULL, ft_philo_routine, philo) != 0)
			return (ft_monitor_error(m, "pthread_create"));
		m->thread.philos[i].initialized = true;
		i++;
	}
	return (true);
}

void	ft_monitor_setup(t_monitor *m, int argc, char *argv[])
{
	m->num = ft_strtoi(argv[1], NULL, 10);
	m->info.time_to_die = ft_strtoi(argv[2], NULL, 10);
	m->info.time_to_eat = ft_strtoi(argv[3], NULL, 10);
	m->info.time_to_sleep = ft_strtoi(argv[4], NULL, 10);
	if (argc == 6)
		m->info.num_of_must_eat = ft_strtoi(argv[5], NULL, 10);
	m->time.routine_interval = ft_max(\
			m->num * 5, MONITOR_ROUTINE_INTERVAL_TIME);
	if (!ft_monitor_alloc_setup(m) \
			|| !ft_monitor_mutex_setup(m) \
			|| !ft_monitor_thread_setup(m))
		return ;
}
