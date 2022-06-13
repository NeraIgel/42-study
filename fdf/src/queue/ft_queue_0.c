/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:41:24 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:32 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_queue.h"

void	ft_queue_init(t_queue *q)
{
	q->size = 0U;
	ft_lstinit(&(q->head));
}

void	ft_queue_clear(t_queue *q)
{
	while (!ft_queue_empty(q))
		ft_queue_pop(q);
}

void	ft_queue_error(t_queue *q, char *errmsg)
{
	if (errmsg)
		ft_putendl_fd(errmsg, STDERR_FILENO);
	ft_queue_clear(q);
	exit(EXIT_FAILURE);
}
