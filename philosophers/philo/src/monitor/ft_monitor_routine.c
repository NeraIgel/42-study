/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:09:58 by heha              #+#    #+#             */
/*   Updated: 2022/07/27 13:25:19 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_monitor.h"

static int	ft_check_philos_interrupt(t_monitor *m)
{
	int		i;
	int		died;
	bool	full_eaten;
	t_philo	*philo;

	i = 0;
	died = 0;
	full_eaten = true;
	while (i < m->num && !died && SIM_STOP != \
			ft_get_monitor_simulation(&(m->mutex.sim.data), &(m->property.sim)))
	{
		philo = &m->shared.philos[i];
		died = ft_check_philo_died(philo);
		if (died < 0)
			return (-1);
		if (!died && full_eaten && !ft_get_philo_full_eaten(philo))
			full_eaten = false;
		i++;
	}
	return (died > 0 || full_eaten);
}

void	ft_monitor_routine(t_monitor *m)
{
	pthread_mutex_t	*mutex;
	t_sim			*valptr;

	if (EXIT_SUCCESS != m->ret)
		return ;
	mutex = &(m->mutex.sim.data);
	valptr = &(m->property.sim);
	ft_set_monitor_simulation(mutex, valptr, SIM_START);
	while (SIM_STOP != ft_get_monitor_simulation(mutex, valptr))
	{
		if (ft_check_philos_interrupt(m) > 0)
			ft_set_monitor_simulation(mutex, valptr, SIM_STOP);
		usleep(m->time.routine_interval);
	}
}
