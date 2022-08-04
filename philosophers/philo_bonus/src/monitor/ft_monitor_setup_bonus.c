/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_setup_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:41:33 by heha              #+#    #+#             */
/*   Updated: 2022/08/04 11:47:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_monitor_bonus.h"
#include "ft_utils_bonus.h"

static void	ft_monitor_info_setup(t_monitor *m, int argc, char *argv[])
{
	m->num = ft_strtoi(argv[1], NULL, 10);
	m->info.time_to_die = ft_strtoi(argv[2], NULL, 10);
	m->info.time_to_eat = ft_strtoi(argv[3], NULL, 10);
	m->info.time_to_sleep = ft_strtoi(argv[4], NULL, 10);
	if (argc == 6)
		m->info.num_of_must_eat = ft_strtoi(argv[5], NULL, 10);
}

static void	ft_monitor_sem_setup(t_monitor *m)
{
	m->sem.print = ft_sem_open("print", 1);
	m->sem.forks = ft_sem_open("forks", m->num);
	m->sem.sim_stop = ft_sem_open("sim_stop", 0);
	m->sem.sim_start = ft_sem_open("sim_start", m->num);
	m->sem.full_eaten = ft_sem_open("full_eaten", 0);
	if (SEM_FAILED == m->sem.print)
		ft_monitor_error(m, "ft_sem_open: print");
	if (SEM_FAILED == m->sem.forks)
		ft_monitor_error(m, "ft_sem_open: forks");
	if (SEM_FAILED == m->sem.sim_stop)
		ft_monitor_error(m, "ft_sem_open: sim_stop");
	if (SEM_FAILED == m->sem.sim_start)
		ft_monitor_error(m, "ft_sem_open: sim_start");
	if (SEM_FAILED == m->sem.full_eaten)
		ft_monitor_error(m, "ft_sem_open: full_eaten");
}

static void	ft_monitor_thread_setup(t_monitor *m)
{
	t_thrd	*thrd;
	void	*(*ft_routine)(void *);

	if (m->info.num_of_must_eat)
	{
		thrd = &(m->thread.check_philos_full_eaten);
		ft_routine = ft_monitor_check_philos_full_eaten;
		if (pthread_create(&(thrd->data), NULL, ft_routine, m) != 0)
			ft_monitor_error(m, "pthread_create");
		thrd->initialized = true;
	}
}

static void	ft_monitor_process_setup(t_monitor *m)
{
	int		i;

	m->process.philos = malloc(sizeof(pid_t) * m->num);
	if (NULL == m->process.philos)
		ft_monitor_error(m, "malloc");
	i = 0;
	while (i < m->num)
		m->process.philos[i++] = -1;
	i = 0;
	while (i < m->num)
	{
		m->process.philos[i] = fork();
		if (m->process.philos[i] < 0)
			ft_monitor_error(m, "fork");
		if (m->process.philos[i] == 0)
			ft_philo_process(m, i);
		i++;
	}
}

void	ft_monitor_setup(t_monitor *m, int argc, char *argv[])
{
	ft_monitor_info_setup(m, argc, argv);
	ft_monitor_sem_setup(m);
	ft_monitor_thread_setup(m);
	ft_monitor_process_setup(m);
}
