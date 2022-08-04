/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_open_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:21:25 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 21:15:53 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>

sem_t	*ft_sem_open(const char *name, unsigned int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (SEM_FAILED != sem)
		if (sem_unlink(name) < 0)
			return (SEM_FAILED);
	return (sem);
}
