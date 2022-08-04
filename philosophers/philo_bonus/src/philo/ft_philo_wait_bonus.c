/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_wait_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:59:29 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 20:53:49 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_philo_bonus.h"

static struct timeval	*ft_get_philo_comparetime(t_philo *p, t_stat stat)
{
	if (PH_THINKING == stat)
		return (&(p->property.think_time));
	else if (PH_SLEEPING == stat)
		return (&(p->property.slept_time));
	else if (PH_EATING == stat)
		return (&(p->property.eaten_time));
	else if (PH_NONE == stat)
		return (&(p->property.start_time));
	else
		return (NULL);
}

static int64_t	ft_get_philo_waittime_in_us(t_philo *p, t_stat stat)
{
	if (PH_THINKING == stat)
		return (p->time.think_wait);
	else if (PH_SLEEPING == stat)
		return (p->info.time_to_sleep * 1000);
	else if (PH_EATING == stat)
		return (p->info.time_to_eat * 1000);
	else if (PH_NONE == stat)
		return (p->time.even_wait);
	else
		return (0);
}

bool	ft_philo_wait(t_philo *p, t_stat stat)
{
	struct timeval	*comparetime;
	int64_t			waittime;
	int64_t			difftime;
	int				check_died;

	comparetime = ft_get_philo_comparetime(p, stat);
	waittime = ft_get_philo_waittime_in_us(p, stat);
	if (comparetime && waittime)
	{
		while (true)
		{
			usleep(p->time.check_interval);
			difftime = ft_get_difftime_in_us(comparetime, NULL);
			if (difftime < 0)
				return (ft_philo_error(p, "gettimeofday", false));
			if (difftime >= waittime)
				break ;
			check_died = ft_check_philo_died(p);
			if (check_died < 0)
				return (false);
			if (check_died > 0)
				break ;
		}
	}
	return (true);
}
