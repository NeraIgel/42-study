/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:34:28 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 12:34:41 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

void	*ft_deque_at(t_deque *dq, size_t n)
{
	t_list	*node;

	if (ft_deque_empty(dq))
		ft_deque_error(dq, ERR_DEQ_EMPTY);
	if (n >= ft_deque_size(dq))
		ft_deque_error(dq, ERR_DEQ_INDEX);
	node = dq->head->next;
	while (n--)
		node = node->next;
	return (node->content);
}

void	*ft_deque_front(t_deque *dq)
{
	t_list	*node;

	if (ft_deque_empty(dq))
		ft_deque_error(dq, ERR_DEQ_EMPTY);
	node = ft_lstfirst(dq->head);
	return (node->content);
}

void	*ft_deque_back(t_deque *dq)
{
	t_list	*node;

	if (ft_deque_empty(dq))
		ft_deque_error(dq, ERR_DEQ_EMPTY);
	node = ft_lstlast(dq->head);
	return (node->content);
}
