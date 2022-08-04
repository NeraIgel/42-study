/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_destroy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:40:14 by heha              #+#    #+#             */
/*   Updated: 2022/08/04 12:06:21 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"
#include "ft_utils_bonus.h"

static void	ft_destroy_error(t_philo *p, const char *errmsg)
{
	if (errmsg)
	{
		sem_wait(p->sem.print);
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
		sem_post(p->sem.print);
	}
	p->ret = EXIT_FAILURE;
}

static void	ft_philo_thread_destroy(t_philo *p)
{
	t_thrd	*thrd;
	void	*ret;

	thrd = &(p->thread.check_died);
	if (thrd->initialized)
	{
		if (pthread_join(thrd->data, &ret) != 0)
			ft_destroy_error(p, "pthread_join");
		else if (EXIT_SUCCESS != (int)ret)
			p->ret = EXIT_FAILURE;
		thrd->initialized = false;
	}
}

static void	ft_philo_sem_destroy(t_philo *p)
{
	if (SEM_FAILED != p->sem.stat && sem_close(p->sem.stat) < 0)
		ft_destroy_error(p, "sem_close: stat");
	p->sem.stat = SEM_FAILED;
}

int	ft_philo_destroy(t_philo *p)
{
	int		exitstatus;

	ft_philo_thread_destroy(p);
	ft_philo_sem_destroy(p);
	exitstatus = p->ret;
	free(p);
	return (exitstatus);
}
