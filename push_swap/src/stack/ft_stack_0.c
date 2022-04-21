/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:23:15 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:06 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stack_init(t_stack *s, \
		int (*cmp)(const void *, const void *), void (*swap)(void *, void *))
{
	s->size = 0U;
	s->cmp = cmp;
	s->swap = swap;
	ft_lstinit(&(s->head));
}

void	ft_stack_clear(t_stack *s)
{
	while (!ft_stack_empty(s))
		ft_stack_pop(s);
}

void	ft_stack_error(t_stack *s, char *errmsg)
{
	if (errmsg)
		ft_putendl_fd(errmsg, STDERR_FILENO);
	ft_stack_clear(s);
	exit(EXIT_FAILURE);
}
