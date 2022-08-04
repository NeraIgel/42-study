/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:37:50 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 20:50:40 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_BONUS_H
# define FT_PHILO_BONUS_H

# include <semaphore.h>
# include <sys/time.h>
# include "ft_structs_bonus.h"

# define MAX_PHILO_STAT					5
# define EVEN_PHILO_WAIT_TIME			300
# define PHILO_THINK_WAIT_TIME			200
# define PHILO_START_INTERVAL_TIME		50
# define PHILO_CHECK_INTERVAL_TIME		100
# define PHILO_THREAD_INTERVAL_TIME		50

typedef enum e_stat
{
	PH_NONE,
	PH_EATING,
	PH_SLEEPING,
	PH_THINKING,
	PH_DIED,
}	t_stat;

typedef struct s_philo_sem
{
	sem_t	*stat;
	sem_t	*print;
	sem_t	*forks;
	sem_t	*sim_stop;
	sem_t	*sim_start;
	sem_t	*full_eaten;
}	t_philo_sem;

typedef struct s_philo_info
{
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_must_eat;
}	t_philo_info;

typedef struct s_philo_time
{
	int		even_wait;
	int		think_wait;
	int		start_interval;
	int		check_interval;
	int		thread_interval;
}	t_philo_time;

typedef struct s_philo_thread
{
	t_thrd	check_died;
}	t_philo_thread;

typedef struct s_philo_property
{
	int				eaten_cnt;
	struct timeval	eaten_time;
	struct timeval	slept_time;
	struct timeval	think_time;
	struct timeval	start_time;
	bool			full_eaten;
}	t_philo_property;

typedef struct s_philo
{
	int					id;
	int					ret;
	t_stat				stat;
	t_philo_sem			sem;
	t_philo_info		info;
	t_philo_time		time;
	t_philo_thread		thread;
	t_philo_property	property;
}	t_philo;

void	ft_philo_init(t_philo *p);
bool	ft_philo_error(t_philo *p, const char *errmsg, bool isexit);
void	ft_philo_setup(t_philo *p);
int		ft_philo_destroy(t_philo *p);
void	*ft_philo_check_died(void *arg);
void	ft_philo_routine(t_philo *p);
void	ft_philo_eat(t_philo *p);
void	ft_philo_sleep(t_philo *p);
void	ft_philo_think(t_philo *p);
bool	ft_philo_print(t_philo *p, t_stat stat);
bool	ft_philo_wait(t_philo *p, t_stat stat);
int64_t	ft_get_difftime_in_ms(struct timeval *time1, struct timeval *time2);
int64_t	ft_get_difftime_in_us(struct timeval *time1, struct timeval *time2);

t_stat	ft_get_philo_stat(t_philo *p);
int		ft_check_philo_died(t_philo *p);
void	ft_set_philo_stat(t_philo *p, t_stat setval);

#endif
