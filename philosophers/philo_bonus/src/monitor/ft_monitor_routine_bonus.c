/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_routine_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:16:57 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 21:50:59 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_monitor_bonus.h"

void	*ft_monitor_check_philos_full_eaten(void *arg)
{
	t_monitor	*m;
	int			i;

	m = (t_monitor *)arg;
	i = 0;
	while (i < m->num)
	{
		if (sem_wait(m->sem.full_eaten) < 0)
			ft_monitor_error(m, "sem_wait: full_eaten");
		i++;
	}
	if (sem_post(m->sem.sim_stop) < 0)
		ft_monitor_error(m, "sem_post: sim_stop");
	return ((void *)EXIT_SUCCESS);
}

void	ft_monitor_routine(t_monitor *m)
{
	int		i;

	i = 0;
	while (i < m->num)
	{
		if (sem_post(m->sem.sim_start) < 0)
			ft_monitor_error(m, "sem_post: sim_start");
		i++;
	}
	if (sem_wait(m->sem.sim_stop) < 0)
		ft_monitor_error(m, "sem_wait: sim_stop");
}
