/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:52:35 by heha              #+#    #+#             */
/*   Updated: 2022/07/27 13:22:07 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MONITOR_H
# define FT_MONITOR_H

# include "ft_philo.h"
# include "ft_structs.h"

# define MONITOR_ROUTINE_INTERVAL_TIME	50

typedef struct s_monitor_info
{
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_must_eat;
}	t_monitor_info;

typedef struct s_monitor_time
{
	int		routine_interval;
}	t_monitor_time;

typedef struct s_monitor_mutex
{
	t_mutex		sim;
	t_mutex		print;
	t_mutex		*forks;
	t_mutex		*philos;
}	t_monitor_mutex;

typedef struct s_monitor_shared
{
	t_philo		*philos;
}	t_monitor_shared;

typedef struct s_monitor_thread
{
	t_thread	*philos;
}	t_monitor_thread;

typedef struct s_monitor_property
{
	t_sim	sim;
}	t_monitor_property;

typedef struct s_monitor
{
	int					ret;
	int					num;
	t_monitor_info		info;
	t_monitor_time		time;
	t_monitor_mutex		mutex;
	t_monitor_shared	shared;
	t_monitor_thread	thread;
	t_monitor_property	property;
}	t_monitor;

void	ft_monitor_init(t_monitor *m);
void	ft_monitor_destroy(t_monitor *m);
bool	ft_monitor_error(t_monitor *m, const char *errmsg);
void	ft_monitor_setup(t_monitor *m, int argc, char *argv[]);
void	ft_monitor_routine(t_monitor *m);

t_sim	ft_get_monitor_simulation(\
		pthread_mutex_t *mutex, t_sim *valptr);
void	ft_set_monitor_simulation(\
		pthread_mutex_t *mutex, t_sim *valptr, t_sim setval);

#endif
