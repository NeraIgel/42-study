/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:25:30 by heha              #+#    #+#             */
/*   Updated: 2022/07/26 16:57:14 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"
#include "ft_utils.h"

static void	ft_even_philo_swap_fork(t_philo *p)
{
	pthread_mutex_t	*mutex;

	mutex = p->mutex.fork1;
	p->mutex.fork1 = p->mutex.fork2;
	p->mutex.fork2 = mutex;
}

bool	ft_philo_init(t_philo *p)
{
	if (p->id % 2 == 0)
		ft_even_philo_swap_fork(p);
	if (gettimeofday(&(p->property.start_time), NULL) < 0)
		return (ft_philo_error(p, "gettimeofday"));
	p->property.think_time.tv_usec = p->property.start_time.tv_usec;
	p->property.think_time.tv_sec = p->property.start_time.tv_sec;
	p->property.slept_time.tv_usec = p->property.start_time.tv_usec;
	p->property.slept_time.tv_sec = p->property.start_time.tv_sec;
	p->property.eaten_time.tv_usec = p->property.start_time.tv_usec;
	p->property.eaten_time.tv_sec = p->property.start_time.tv_sec;
	ft_set_philo_stat(p, PH_NONE);
	if (!ft_philo_print(p, PH_NONE))
		return (false);
	return (true);
}

bool	ft_philo_error(t_philo *p, const char *errmsg)
{
	ft_set_philo_simulation(p->mutex.sim, p->shared.sim, SIM_STOP);
	if (errmsg)
	{
		pthread_mutex_lock(p->mutex.print);
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
		pthread_mutex_unlock(p->mutex.print);
	}
	return (false);
}
