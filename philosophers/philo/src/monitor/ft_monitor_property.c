/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_property.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:39:58 by heha              #+#    #+#             */
/*   Updated: 2022/07/26 13:40:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "ft_enums.h"

t_sim	ft_get_monitor_simulation(\
		pthread_mutex_t *mutex, t_sim *valptr)
{
	t_sim	ret;

	pthread_mutex_lock(mutex);
	ret = *valptr;
	pthread_mutex_unlock(mutex);
	return (ret);
}

void	ft_set_monitor_simulation(\
		pthread_mutex_t *mutex, t_sim *valptr, t_sim setval)
{
	pthread_mutex_lock(mutex);
	*valptr = setval;
	pthread_mutex_unlock(mutex);
}
