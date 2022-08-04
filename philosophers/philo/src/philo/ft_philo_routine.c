/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_routine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:32:14 by heha              #+#    #+#             */
/*   Updated: 2022/07/27 13:32:50 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_philo.h"

static bool	ft_philo_waiting_for_start(t_philo *p)
{
	while (SIM_NONE == ft_get_philo_simulation(p->mutex.sim, p->shared.sim))
		usleep(p->time.start_interval);
	if (p->id % 2 == 0 && !ft_philo_wait(p, PH_NONE))
		return (false);
	ft_set_philo_stat(p, PH_SLEEPING);
	return (true);
}

void	*ft_philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (!ft_philo_init(p) || !ft_philo_waiting_for_start(p))
		return ((void *)EXIT_FAILURE);
	while (SIM_STOP != ft_get_philo_simulation(p->mutex.sim, p->shared.sim))
		if (!ft_philo_eat(p) || !ft_philo_sleep(p) || !ft_philo_think(p))
			return ((void *)EXIT_FAILURE);
	return ((void *)EXIT_SUCCESS);
}
