/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_execute_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:59:01 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 21:40:00 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"

static bool	ft_philo_eaten_update(t_philo *p)
{
	if (p->info.num_of_must_eat \
			&& ++(p->property.eaten_cnt) >= p->info.num_of_must_eat)
	{
		p->property.full_eaten = true;
		if (sem_post(p->sem.full_eaten) < 0)
		{
			ft_philo_error(p, "sem_post: full_eaten", false);
			return (false);
		}
	}
	return (true);
}

void	ft_philo_eat(t_philo *p)
{
	int		check_died;
	t_stat	stat;

	if (false == p->property.full_eaten && PH_THINKING == ft_get_philo_stat(p))
	{
		if (sem_wait(p->sem.forks) < 0 || sem_wait(p->sem.forks) < 0)
			ft_philo_error(p, "sem_wait: forks", true);
		check_died = ft_check_philo_died(p);
		if (!check_died)
		{
			stat = PH_EATING;
			ft_set_philo_stat(p, stat);
			if (!ft_philo_print(p, stat))
				check_died = -1;
			if (!check_died && !ft_philo_wait(p, stat))
				check_died = -1;
			if (!check_died && !ft_philo_eaten_update(p))
				check_died = -1;
		}
		if (sem_post(p->sem.forks) < 0 || sem_post(p->sem.forks) < 0)
			ft_philo_error(p, "sem_post: forks", true);
		if (check_died < 0)
			ft_philo_error(p, NULL, true);
	}
}

void	ft_philo_sleep(t_philo *p)
{
	int		check_died;
	t_stat	stat;

	if (PH_EATING == ft_get_philo_stat(p))
	{
		check_died = ft_check_philo_died(p);
		if (!check_died)
		{
			stat = PH_SLEEPING;
			ft_set_philo_stat(p, stat);
			if (!ft_philo_print(p, stat) || !ft_philo_wait(p, stat))
				ft_philo_error(p, NULL, true);
		}
		if (check_died < 0)
			ft_philo_error(p, NULL, true);
	}
}

void	ft_philo_think(t_philo *p)
{
	int		check_died;
	t_stat	stat;

	if (PH_SLEEPING == ft_get_philo_stat(p))
	{
		check_died = ft_check_philo_died(p);
		if (!check_died)
		{
			stat = PH_THINKING;
			ft_set_philo_stat(p, stat);
			if (!ft_philo_print(p, stat) || !ft_philo_wait(p, stat))
				ft_philo_error(p, NULL, true);
		}
		if (check_died < 0)
			ft_philo_error(p, NULL, true);
	}
}
