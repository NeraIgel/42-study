/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:07:34 by heha              #+#    #+#             */
/*   Updated: 2022/07/27 13:28:00 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "ft_enums.h"

# define MAX_PHILO_STAT					5
# define EVEN_PHILO_WAIT_TIME			300
# define PHILO_THINK_WAIT_TIME			200
# define PHILO_START_INTERVAL_TIME		50
# define PHILO_CHECK_INTERVAL_TIME		100

typedef enum e_stat
{
	PH_NONE,
	PH_EATING,
	PH_SLEEPING,
	PH_THINKING,
	PH_DIED,
}	t_stat;

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
}	t_philo_time;

typedef struct s_philo_mutex
{
	pthread_mutex_t	*sim;
	pthread_mutex_t	*print;
	pthread_mutex_t	*self;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
}	t_philo_mutex;

typedef struct s_philo_shared
{
	t_sim	*sim;
}	t_philo_shared;

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
	t_stat				stat;
	t_philo_info		info;
	t_philo_time		time;
	t_philo_mutex		mutex;
	t_philo_shared		shared;
	t_philo_property	property;
}	t_philo;

bool	ft_philo_init(t_philo *p);
bool	ft_philo_error(t_philo *p, const char *errmsg);
void	*ft_philo_routine(void *arg);
bool	ft_philo_eat(t_philo *p);
bool	ft_philo_sleep(t_philo *p);
bool	ft_philo_think(t_philo *p);
bool	ft_philo_print(t_philo *p, t_stat stat);
bool	ft_philo_wait(t_philo *p, t_stat stat);
int64_t	ft_get_difftime_in_ms(struct timeval *time1, struct timeval *time2);
int64_t	ft_get_difftime_in_us(struct timeval *time1, struct timeval *time2);

bool	ft_get_philo_full_eaten(t_philo *p);
void	ft_set_philo_full_eaten(t_philo *p, bool setval);

t_stat	ft_get_philo_stat(t_philo *p);
int		ft_check_philo_died(t_philo *p);
void	ft_set_philo_stat(t_philo *p, t_stat setval);

t_sim	ft_get_philo_simulation(\
		pthread_mutex_t *mutex, t_sim *valptr);
void	ft_set_philo_simulation(\
		pthread_mutex_t *mutex, t_sim *valptr, t_sim setval);

#endif
