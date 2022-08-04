/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_setup_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:16:59 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 21:13:45 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"
#include "ft_utils_bonus.h"

static void	ft_philo_sem_setup(t_philo *p)
{
	p->sem.stat = ft_sem_open("stat", 1);
	if (SEM_FAILED == p->sem.stat)
		ft_philo_error(p, "ft_sem_open: stat", true);
}

static void	ft_philo_property_setup(t_philo *p)
{
	if (gettimeofday(&(p->property.start_time), NULL) < 0)
		ft_philo_error(p, "gettimeofday", true);
	p->property.think_time.tv_usec = p->property.start_time.tv_usec;
	p->property.think_time.tv_sec = p->property.start_time.tv_sec;
	p->property.slept_time.tv_usec = p->property.start_time.tv_usec;
	p->property.slept_time.tv_sec = p->property.start_time.tv_sec;
	p->property.eaten_time.tv_usec = p->property.start_time.tv_usec;
	p->property.eaten_time.tv_sec = p->property.start_time.tv_sec;
	ft_set_philo_stat(p, PH_NONE);
	if (!ft_philo_print(p, PH_NONE))
		ft_philo_error(p, NULL, true);
}

static void	ft_philo_thread_setup(t_philo *p)
{
	t_thrd	*thrd;
	void	*(*ft_routine)(void *);

	thrd = &(p->thread.check_died);
	ft_routine = ft_philo_check_died;
	if (pthread_create(&(thrd->data), NULL, ft_routine, p) != 0)
		ft_philo_error(p, "pthread_create", true);
	thrd->initialized = true;
}

void	ft_philo_setup(t_philo *p)
{
	ft_philo_sem_setup(p);
	ft_philo_property_setup(p);
	ft_philo_thread_setup(p);
}
