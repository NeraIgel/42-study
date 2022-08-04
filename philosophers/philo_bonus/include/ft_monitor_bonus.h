/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:33:30 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 14:38:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MONITOR_BONUS_H
# define FT_MONITOR_BONUS_H

# include <semaphore.h>
# include <unistd.h>
# include "ft_structs_bonus.h"

typedef struct s_monitor_sem
{
	sem_t	*print;
	sem_t	*forks;
	sem_t	*sim_stop;
	sem_t	*sim_start;
	sem_t	*full_eaten;
}	t_monitor_sem;

typedef struct s_monitor_info
{
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_must_eat;
}	t_monitor_info;

typedef struct s_monitor_thread
{
	t_thrd	check_philos_full_eaten;
}	t_monitor_thread;

typedef struct s_monitor_process
{
	pid_t	*philos;
}	t_monitor_process;

typedef struct s_monitor
{
	int					ret;
	int					num;
	t_monitor_sem		sem;
	t_monitor_info		info;
	t_monitor_thread	thread;
	t_monitor_process	process;
}	t_monitor;

void	ft_monitor_init(t_monitor *m);
void	ft_monitor_destroy(t_monitor *m);
void	ft_monitor_error(t_monitor *m, const char *errmsg);
void	ft_monitor_setup(t_monitor *m, int argc, char *argv[]);
void	*ft_monitor_check_philos_full_eaten(void *arg);
void	ft_monitor_routine(t_monitor *m);

void	ft_philo_process(t_monitor *m, int i);

#endif
