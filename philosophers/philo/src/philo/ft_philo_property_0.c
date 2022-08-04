/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_property_0.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:01:32 by heha              #+#    #+#             */
/*   Updated: 2022/07/26 17:06:29 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

bool	ft_get_philo_full_eaten(t_philo *p)
{
	bool	ret;

	if (p->info.num_of_must_eat)
	{
		pthread_mutex_lock(p->mutex.self);
		ret = p->property.full_eaten;
		pthread_mutex_unlock(p->mutex.self);
	}
	else
		ret = false;
	return (ret);
}

void	ft_set_philo_full_eaten(t_philo *p, bool setval)
{
	pthread_mutex_lock(p->mutex.self);
	p->property.full_eaten = setval;
	pthread_mutex_unlock(p->mutex.self);
}
