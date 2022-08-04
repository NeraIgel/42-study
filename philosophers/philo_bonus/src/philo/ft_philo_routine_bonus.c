/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:48:10 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 21:34:08 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_philo_bonus.h"

static void	ft_philo_waiting_for_start(t_philo *p)
{
	if (sem_wait(p->sem.sim_start) < 0)
		ft_philo_error(p, "sem_wait: sim_start", true);
	if (p->id % 2 == 0 && !ft_philo_wait(p, PH_NONE))
		ft_philo_error(p, NULL, true);
	ft_set_philo_stat(p, PH_SLEEPING);
}

void	*ft_philo_check_died(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (!ft_check_philo_died(p))
		usleep(p->time.thread_interval);
	return ((void *)EXIT_SUCCESS);
}

void	ft_philo_routine(t_philo *p)
{
	ft_philo_init(p);
	ft_philo_setup(p);
	ft_philo_waiting_for_start(p);
	while (true)
	{
		ft_philo_eat(p);
		ft_philo_sleep(p);
		ft_philo_think(p);
	}
	exit(ft_philo_destroy(p));
}
