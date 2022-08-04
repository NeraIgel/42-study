/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:25:25 by heha              #+#    #+#             */
/*   Updated: 2022/07/26 17:25:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

static bool	ft_get_difftime(\
		int64_t *diff_sec, int64_t *diff_usec, \
		struct timeval *time1, struct timeval *time2)
{
	struct timeval	cur_time;

	if (!time2)
	{
		if (gettimeofday(&(cur_time), NULL) < 0)
			return (false);
		*diff_sec = cur_time.tv_sec - time1->tv_sec;
		*diff_usec = cur_time.tv_usec - time1->tv_usec;
	}
	else
	{
		*diff_sec = time2->tv_sec - time1->tv_sec;
		*diff_usec = time2->tv_usec - time1->tv_usec;
	}
	return (true);
}

int64_t	ft_get_difftime_in_ms(struct timeval *time1, struct timeval *time2)
{
	int64_t		diff_sec;
	int64_t		diff_usec;
	int64_t		diff_time;

	if (!ft_get_difftime(&diff_sec, &diff_usec, time1, time2))
		return (-1);
	diff_time = (diff_sec * 1000) + (diff_usec / 1000);
	return (diff_time);
}

int64_t	ft_get_difftime_in_us(struct timeval *time1, struct timeval *time2)
{
	int64_t		diff_sec;
	int64_t		diff_usec;
	int64_t		diff_time;

	if (!ft_get_difftime(&diff_sec, &diff_usec, time1, time2))
		return (-1);
	diff_time = (diff_sec * 1000000) + diff_usec;
	return (diff_time);
}
