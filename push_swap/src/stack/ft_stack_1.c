/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:26:40 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:08 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	ft_stack_size(const t_stack *s)
{
	return (s->size);
}

bool	ft_stack_empty(const t_stack *s)
{
	return (s->size == 0U);
}

void	ft_stack_iter(t_stack *s, void (*f)(void *))
{
	ft_lstiter(&(s->head), f);
}
