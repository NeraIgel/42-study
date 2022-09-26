/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:34:06 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 12:34:14 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

size_t	ft_deque_size(const t_deque *dq)
{
	return (dq->size);
}

bool	ft_deque_empty(const t_deque *dq)
{
	return (0U == dq->size);
}

void	ft_deque_iter(t_deque *dq, void (*f)(void *))
{
	ft_lstiter(dq->head, f);
}
