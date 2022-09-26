/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:34:01 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 12:34:03 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	ft_deque_create(t_deque *dq)
{
	dq->head = (t_list *)malloc(sizeof(t_list));
	if (!(dq->head))
		ft_deque_error(dq, ERR_DEQ_MALLOC);
	ft_lstinit(dq->head);
	dq->size = 0U;
}

void	ft_deque_destroy(t_deque *dq)
{
	if (dq->head)
	{
		ft_deque_clear(dq);
		free(dq->head);
		dq->head = NULL;
	}
}

void	ft_deque_clear(t_deque *dq)
{
	while (!ft_deque_empty(dq))
		ft_deque_pop(dq);
}

void	ft_deque_error(t_deque *dq, const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	ft_deque_destroy(dq);
	exit(EXIT_FAILURE);
}
