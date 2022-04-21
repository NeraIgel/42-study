/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:35:16 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

bool	ft_stack_check_dist(t_stack *s)
{
	t_list			*node;
	t_list			*find;
	const t_list	*head = &(s->head);

	if (s->cmp == NULL)
		ft_stack_error(s, ERR_STK_FUNC);
	node = head->next;
	while (node != head)
	{
		find = node->next;
		while (find != head)
		{
			if (s->cmp(node->content, find->content) == 0)
				return (false);
			find = find->next;
		}
		node = node->next;
	}
	return (true);
}

bool	ft_stack_check_sort(t_stack *s)
{
	t_list			*node;
	t_list			*next;
	const t_list	*head = &(s->head);

	if (s->cmp == NULL)
		ft_stack_error(s, ERR_STK_FUNC);
	node = head->next;
	while (node != head)
	{
		next = node->next;
		if (next != head)
		{
			if (s->cmp(node->content, next->content) > 0)
				return (false);
		}
		node = next;
	}
	return (true);
}

size_t	ft_stack_get_minidx(t_stack *s)
{
	size_t			idx;
	size_t			min_idx;
	t_list			*node;
	t_list			*min_node;
	const t_list	*head = &(s->head);

	if (s->cmp == NULL)
		ft_stack_error(s, ERR_STK_FUNC);
	if (ft_stack_empty(s))
		ft_stack_error(s, ERR_STK_EMPTY);
	idx = 0U;
	min_idx = 0U;
	node = head->next;
	min_node = head->next;
	while (node != head)
	{
		if (s->cmp(node->content, min_node->content) < 0)
		{
			min_idx = idx;
			min_node = node;
		}
		idx++;
		node = node->next;
	}
	return (min_idx);
}

size_t	ft_stack_get_maxidx(t_stack *s)
{
	size_t			idx;
	size_t			max_idx;
	t_list			*node;
	t_list			*max_node;
	const t_list	*head = &(s->head);

	if (s->cmp == NULL)
		ft_stack_error(s, ERR_STK_FUNC);
	if (ft_stack_empty(s))
		ft_stack_error(s, ERR_STK_EMPTY);
	idx = 0U;
	max_idx = 0U;
	node = head->next;
	max_node = head->next;
	while (node != head)
	{
		if (s->cmp(node->content, max_node->content) > 0)
		{
			max_idx = idx;
			max_node = node;
		}
		idx++;
		node = node->next;
	}
	return (max_idx);
}
