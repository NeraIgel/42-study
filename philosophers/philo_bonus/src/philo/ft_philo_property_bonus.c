/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_property_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:59:42 by heha              #+#    #+#             */
/*   Updated: 2022/08/04 12:30:17 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_philo_bonus.h"

static int	ft_check_error(t_philo *p, const char *errmsg)
{
	ft_philo_error(p, errmsg, false);
	return (-1);
}

static bool	ft_philo_died(t_philo *p)
{
	if (!ft_philo_print(p, PH_DIED))
		return (false);
	if (sem_post(p->sem.sim_stop) < 0)
		return (ft_philo_error(p, "sem_post: sim_stop", false));
	return (true);
}

int	ft_check_philo_died(t_philo *p)
{
	int		check_died;
	int64_t	fasting_time;

	check_died = 0;
	if (sem_wait(p->sem.stat) < 0)
		return (ft_check_error(p, "sem_wait: stat"));
	if (PH_DIED == p->stat)
		check_died = 2;
	else if (false == p->property.full_eaten \
			&& PH_NONE != p->stat && PH_EATING != p->stat)
	{
		fasting_time = ft_get_difftime_in_ms(&(p->property.eaten_time), NULL);
		if (fasting_time < 0)
			check_died = ft_check_error(p, "gettimeofday");
		else if (fasting_time >= p->info.time_to_die)
		{
			p->stat = PH_DIED;
			check_died = 1;
		}
	}
	if (sem_post(p->sem.stat) < 0)
		return (ft_check_error(p, "sem_post: stat"));
	if (1 == check_died && !ft_philo_died(p))
		check_died = -1;
	return (check_died);
}

t_stat	ft_get_philo_stat(t_philo *p)
{
	t_stat	ret;

	if (sem_wait(p->sem.stat) < 0)
		ft_philo_error(p, "sem_wait: stat", true);
	ret = p->stat;
	if (sem_post(p->sem.stat) < 0)
		ft_philo_error(p, "sem_post: stat", true);
	return (ret);
}

void	ft_set_philo_stat(t_philo *p, t_stat setval)
{
	if (sem_wait(p->sem.stat) < 0)
		ft_philo_error(p, "sem_wait: stat", true);
	p->stat = setval;
	if (sem_post(p->sem.stat) < 0)
		ft_philo_error(p, "sem_post: stat", true);
}
