/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:39:53 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:17 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_sort(t_stack *s)
{
	size_t			i;
	size_t			j;
	t_list			*node;
	const t_list	*head = &(s->head);

	if (s->cmp == NULL || s->swap == NULL)
		ft_stack_error(s, ERR_STK_FUNC);
	if (s->size >= 2)
	{
		i = s->size - 1;
		while (i > 0)
		{
			j = 0U;
			node = head->next;
			while (j < i)
			{
				if (s->cmp(node->content, node->next->content) > 0)
					s->swap(node->content, node->next->content);
				node = node->next;
				j++;
			}
			i--;
		}
	}
}

size_t	ft_stack_get_idx(t_stack *s, void *content)
{
	size_t			idx;
	t_list			*node;
	const t_list	*head = &(s->head);

	if (s->cmp == NULL)
		ft_stack_error(s, ERR_STK_FUNC);
	if (ft_stack_empty(s))
		ft_stack_error(s, ERR_STK_EMPTY);
	idx = 0U;
	node = head->next;
	while (node != head && s->cmp(node->content, content))
	{
		idx++;
		node = node->next;
	}
	if (node == head)
		ft_stack_error(s, ERR_STK_FIND);
	return (idx);
}

void	ft_stack_copy(t_stack *dst, const t_stack *src, size_t n)
{
	t_list			*node;
	const t_list	*head = &(src->head);

	node = head->next;
	while (node != head)
	{
		ft_stack_push_back(dst, node->content, n);
		node = node->next;
	}
}
