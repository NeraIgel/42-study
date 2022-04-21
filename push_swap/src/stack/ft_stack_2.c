/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:27:54 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:11 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

static void	ft_content_del(void *content)
{
	free(content);
}

void	ft_stack_push(t_stack *s, void *content, size_t n)
{
	t_list	*node;

	if (!content || !n)
		ft_stack_error(s, ERR_STK_DATA);
	node = ft_lstnew(content);
	if (!node)
		ft_stack_error(s, ERR_STK_MALLOC);
	node->content = malloc(n);
	if (!(node->content))
	{
		free(node);
		ft_stack_error(s, ERR_STK_MALLOC);
	}
	ft_memcpy(node->content, content, n);
	ft_lstadd_front(&(s->head), node);
	s->size++;
}

void	ft_stack_push_back(t_stack *s, void *content, size_t n)
{
	t_list	*node;

	if (!content || !n)
		ft_stack_error(s, ERR_STK_DATA);
	node = ft_lstnew(content);
	if (!node)
		ft_stack_error(s, ERR_STK_MALLOC);
	node->content = malloc(n);
	if (!(node->content))
	{
		free(node);
		ft_stack_error(s, ERR_STK_MALLOC);
	}
	ft_memcpy(node->content, content, n);
	ft_lstadd_back(&(s->head), node);
	s->size++;
}

void	ft_stack_pop(t_stack *s)
{
	t_list	*node;

	if (ft_stack_empty(s))
		ft_stack_error(s, ERR_STK_EMPTY);
	node = ft_lstfirst(&(s->head));
	ft_lstdelone(node, ft_content_del);
	s->size--;
}

void	*ft_stack_top(t_stack *s)
{
	t_list	*node;

	if (ft_stack_empty(s))
		ft_stack_error(s, ERR_STK_EMPTY);
	node = ft_lstfirst(&(s->head));
	return (node->content);
}
