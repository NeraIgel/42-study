/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:41:00 by heha              #+#    #+#             */
/*   Updated: 2022/07/28 20:45:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	ft_philo_eaten_update(t_philo *p)
{
	if (++(p->property.eaten_cnt) >= p->info.num_of_must_eat)
		ft_set_philo_full_eaten(p, true);
}

bool	ft_philo_eat(t_philo *p)
{
	int		check_died;
	t_stat	stat;

	if (p->mutex.fork1 != p->mutex.fork2 && !ft_get_philo_full_eaten(p) \
			&& PH_THINKING == ft_get_philo_stat(p) && SIM_STOP != \
			ft_get_philo_simulation(p->mutex.sim, p->shared.sim))
	{
		pthread_mutex_lock(p->mutex.fork1);
		pthread_mutex_lock(p->mutex.fork2);
		check_died = ft_check_philo_died(p);
		if (!check_died)
		{
			stat = PH_EATING;
			ft_set_philo_stat(p, stat);
			if (!ft_philo_print(p, stat) || !ft_philo_wait(p, stat))
				check_died = -1;
			if (!check_died && p->info.num_of_must_eat)
				ft_philo_eaten_update(p);
		}
		pthread_mutex_unlock(p->mutex.fork2);
		pthread_mutex_unlock(p->mutex.fork1);
		if (check_died < 0)
			return (false);
	}
	return (true);
}

bool	ft_philo_sleep(t_philo *p)
{
	int		check_died;
	t_stat	stat;

	if (PH_EATING == ft_get_philo_stat(p) \
			&& SIM_STOP != ft_get_philo_simulation(p->mutex.sim, p->shared.sim))
	{
		check_died = ft_check_philo_died(p);
		if (!check_died)
		{
			stat = PH_SLEEPING;
			ft_set_philo_stat(p, stat);
			if (!ft_philo_print(p, stat) || !ft_philo_wait(p, stat))
				return (false);
		}
		if (check_died < 0)
			return (false);
	}
	return (true);
}

bool	ft_philo_think(t_philo *p)
{
	int		check_died;
	t_stat	stat;

	if (PH_SLEEPING == ft_get_philo_stat(p) \
			&& SIM_STOP != ft_get_philo_simulation(p->mutex.sim, p->shared.sim))
	{
		check_died = ft_check_philo_died(p);
		if (!check_died)
		{
			stat = PH_THINKING;
			ft_set_philo_stat(p, stat);
			if (!ft_philo_print(p, stat) || !ft_philo_wait(p, stat))
				return (false);
		}
		if (check_died < 0)
			return (false);
	}
	return (true);
}
