/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:30:30 by heha              #+#    #+#             */
/*   Updated: 2022/07/29 13:52:39 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"
#include "ft_utils.h"

static bool	ft_get_philo_comparetime(\
		struct timeval **cmptime, t_philo *p, t_stat stat)
{
	if (PH_THINKING == stat)
	{
		if (gettimeofday(&(p->property.think_time), NULL) < 0)
			return (false);
		*cmptime = &(p->property.think_time);
	}
	else if (PH_SLEEPING == stat)
	{
		if (gettimeofday(&(p->property.slept_time), NULL) < 0)
			return (false);
		*cmptime = &(p->property.slept_time);
	}
	else if (PH_EATING == stat)
	{
		if (gettimeofday(&(p->property.eaten_time), NULL) < 0)
			return (false);
		*cmptime = &(p->property.eaten_time);
	}
	else if (PH_NONE == stat)
		*cmptime = &(p->property.start_time);
	else
		*cmptime = NULL;
	return (true);
}

bool	ft_philo_print(t_philo *p, t_stat stat)
{
	static char		*msgtbl[MAX_PHILO_STAT] = {" has taken a fork", \
		" is eating", " is sleeping", " is thinking", " died"};
	static char		*clrtbl[MAX_PHILO_STAT] = {"\033[32;1m", \
		"\033[33;1m", "\033[33;1m", "\033[33;1m", "\033[31;1m"};
	struct timeval	*cmptime;
	int64_t			timestamp;

	if (!ft_get_philo_full_eaten(p))
	{
		if (!ft_get_philo_comparetime(&cmptime, p, stat))
			return (ft_philo_error(p, "gettimeofday"));
		timestamp = ft_get_difftime_in_ms(&(p->property.start_time), cmptime);
		if (timestamp < 0)
			return (ft_philo_error(p, "gettimeofday"));
		pthread_mutex_lock(p->mutex.print);
		ft_putstr_fd(clrtbl[stat], STDOUT_FILENO);
		ft_putnbr_fd(timestamp, STDOUT_FILENO);
		ft_putstr_fd(" philo_", STDOUT_FILENO);
		ft_putnbr_fd(p->id, STDOUT_FILENO);
		ft_putstr_fd(msgtbl[stat], STDOUT_FILENO);
		ft_putendl_fd("\033[0m", STDOUT_FILENO);
		pthread_mutex_unlock(p->mutex.print);
	}
	return (true);
}
