/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_print_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:59:16 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 21:15:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"
#include "ft_utils_bonus.h"

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

static void	ft_print(\
		const char *clr, int64_t timestamp, int id, const char *msg)
{
	ft_putstr_fd((char *)clr, STDOUT_FILENO);
	ft_putnbr_fd(timestamp, STDOUT_FILENO);
	ft_putstr_fd(" philo_", STDOUT_FILENO);
	ft_putnbr_fd(id, STDOUT_FILENO);
	ft_putstr_fd((char *)msg, STDOUT_FILENO);
	ft_putendl_fd("\033[0m", STDOUT_FILENO);
}

bool	ft_philo_print(t_philo *p, t_stat stat)
{
	static char		*msgtbl[MAX_PHILO_STAT] = {" has taken a fork", \
		" is eating", " is sleeping", " is thinking", " died"};
	static char		*clrtbl[MAX_PHILO_STAT] = {"\033[32;1m", \
		"\033[33;1m", "\033[33;1m", "\033[33;1m", "\033[31;1m"};
	struct timeval	*cmptime;
	int64_t			timestamp;

	if (false == p->property.full_eaten)
	{
		if (!ft_get_philo_comparetime(&cmptime, p, stat))
			return (ft_philo_error(p, "gettimeofday", false));
		timestamp = ft_get_difftime_in_ms(&(p->property.start_time), cmptime);
		if (timestamp < 0)
			return (ft_philo_error(p, "gettimeofday", false));
		if (sem_wait(p->sem.print) < 0)
			return (ft_philo_error(p, "sem_wait: print", false));
		ft_print(clrtbl[stat], timestamp, p->id, msgtbl[stat]);
		if (sem_post(p->sem.print) < 0)
			return (ft_philo_error(p, "sem_post: print", false));
	}
	return (true);
}
