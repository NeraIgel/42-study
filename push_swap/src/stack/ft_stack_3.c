/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:34:38 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:13 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_swap(t_stack *s)
{
	t_list	*node1;
	t_list	*node2;

	if (ft_stack_size(s) >= 2)
	{
		node1 = ft_lstfirst(&(s->head));
		node2 = node1->next;
		node1->prev->next = node2;
		node2->next->prev = node1;
		node2->prev = node1->prev;
		node1->next = node2->next;
		node1->prev = node2;
		node2->next = node1;
	}
}

void	ft_stack_rotate(t_stack *s)
{
	t_list	*first;
	t_list	*last;

	if (ft_stack_size(s) >= 2)
	{
		first = ft_lstfirst(&(s->head));
		last = ft_lstlast(&(s->head));
		first->prev->next = first->next;
		first->next->prev = first->prev;
		first->prev = last;
		first->next = last->next;
		last->next->prev = first;
		last->next = first;
	}
}

void	ft_stack_reverse_rotate(t_stack *s)
{
	t_list	*first;
	t_list	*last;

	if (ft_stack_size(s) >= 2)
	{
		first = ft_lstfirst(&(s->head));
		last = ft_lstlast(&(s->head));
		last->prev->next = last->next;
		last->next->prev = last->prev;
		last->prev = first->prev;
		last->next = first;
		first->prev->next = last;
		first->prev = last;
	}
}
