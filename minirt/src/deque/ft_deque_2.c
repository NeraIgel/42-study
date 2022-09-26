/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:34:17 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 12:34:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque.h"

static void	ft_content_del(void *content)
{
	free(content);
	content = NULL;
}

void	ft_deque_push(t_deque *dq, void *content, size_t n)
{
	t_list	*node;

	if (!content || !n)
		ft_deque_error(dq, ERR_DEQ_DATA);
	node = ft_lstnew(content);
	if (!node)
		ft_deque_error(dq, ERR_DEQ_MALLOC);
	node->content = malloc(n);
	if (!(node->content))
	{
		free(node);
		ft_deque_error(dq, ERR_DEQ_MALLOC);
	}
	ft_memcpy(node->content, content, n);
	ft_lstadd_back(dq->head, node);
	dq->size++;
}

void	ft_deque_pop(t_deque *dq)
{
	t_list	*node;

	if (ft_deque_empty(dq))
		ft_deque_error(dq, ERR_DEQ_EMPTY);
	node = ft_lstfirst(dq->head);
	ft_lstdelone(node, ft_content_del);
	dq->size--;
}
