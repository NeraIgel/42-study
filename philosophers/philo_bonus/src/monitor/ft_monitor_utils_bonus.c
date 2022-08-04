/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:22:55 by heha              #+#    #+#             */
/*   Updated: 2022/08/04 12:39:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_monitor_bonus.h"
#include "ft_philo_bonus.h"
#include "ft_utils_bonus.h"

void	ft_philo_process(t_monitor *m, int i)
{
	t_philo	*p;

	p = ft_calloc(1, sizeof(t_philo));
	if (!p)
	{
		ft_putstr_fd("\033[31;1mError:\033[0m malloc", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	p->id = i + 1;
	p->sem.print = m->sem.print;
	p->sem.forks = m->sem.forks;
	p->sem.sim_stop = m->sem.sim_stop;
	p->sem.sim_start = m->sem.sim_start;
	p->sem.full_eaten = m->sem.full_eaten;
	p->info.time_to_die = m->info.time_to_die;
	p->info.time_to_eat = m->info.time_to_eat;
	p->info.time_to_sleep = m->info.time_to_sleep;
	p->info.num_of_must_eat = m->info.num_of_must_eat;
	p->time.even_wait = ft_max(m->num * 15, EVEN_PHILO_WAIT_TIME);
	p->time.think_wait = PHILO_THINK_WAIT_TIME;
	p->time.start_interval = PHILO_START_INTERVAL_TIME;
	p->time.check_interval = ft_max(m->num * 5, PHILO_CHECK_INTERVAL_TIME);
	p->time.thread_interval = ft_max(m->num * 5, PHILO_THREAD_INTERVAL_TIME);
	ft_philo_routine(p);
}
