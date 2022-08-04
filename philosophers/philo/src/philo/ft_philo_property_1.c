/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_property_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:07:18 by heha              #+#    #+#             */
/*   Updated: 2022/07/28 20:58:40 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"
#include "ft_utils.h"

static int	ft_error(t_philo *p, const char *errmsg)
{
	ft_set_philo_simulation(p->mutex.sim, p->shared.sim, SIM_STOP);
	if (errmsg)
	{
		pthread_mutex_lock(p->mutex.print);
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
		pthread_mutex_unlock(p->mutex.print);
	}
	return (-1);
}

int	ft_check_philo_died(t_philo *p)
{
	int		check_died;
	int64_t	fasting_time;

	check_died = 0;
	pthread_mutex_lock(p->mutex.self);
	if (PH_DIED == p->stat)
		check_died = 2;
	else if (!p->property.full_eaten \
			&& PH_NONE != p->stat && PH_EATING != p->stat)
	{
		fasting_time = ft_get_difftime_in_ms(&(p->property.eaten_time), NULL);
		if (fasting_time < 0)
			check_died = ft_error(p, "gettimeofday");
		else if (fasting_time >= p->info.time_to_die)
		{
			p->stat = PH_DIED;
			check_died = 1;
		}
	}
	pthread_mutex_unlock(p->mutex.self);
	if (1 == check_died)
		ft_set_philo_simulation(p->mutex.sim, p->shared.sim, SIM_STOP);
	if (1 == check_died && !ft_philo_print(p, PH_DIED))
		check_died = -1;
	return (check_died);
}

t_stat	ft_get_philo_stat(t_philo *p)
{
	t_stat	ret;

	pthread_mutex_lock(p->mutex.self);
	ret = p->stat;
	pthread_mutex_unlock(p->mutex.self);
	return (ret);
}

void	ft_set_philo_stat(t_philo *p, t_stat setval)
{
	pthread_mutex_lock(p->mutex.self);
	p->stat = setval;
	pthread_mutex_unlock(p->mutex.self);
}
