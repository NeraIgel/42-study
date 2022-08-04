/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:04:34 by heha              #+#    #+#             */
/*   Updated: 2022/08/04 12:05:23 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo_bonus.h"
#include "ft_utils_bonus.h"

void	ft_philo_init(t_philo *p)
{
	p->ret = EXIT_SUCCESS;
	p->sem.stat = SEM_FAILED;
}

bool	ft_philo_error(t_philo *p, const char *errmsg, bool isexit)
{
	if (errmsg)
	{
		sem_wait(p->sem.print);
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
		sem_post(p->sem.print);
	}
	if (isexit)
	{
		sem_post(p->sem.sim_stop);
		ft_philo_destroy(p);
		exit(EXIT_FAILURE);
	}
	return (false);
}
