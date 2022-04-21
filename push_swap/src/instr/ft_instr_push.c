/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:49:07 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:42:12 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_elem.h"
#include "ft_instr.h"

void	ft_instr_pa(t_stack *a, t_stack *b)
{
	t_element	elem;

	if (!ft_stack_empty(b))
	{
		elem = *(t_element *)ft_stack_top(b);
		ft_stack_push(a, &elem, sizeof(t_element));
		ft_stack_pop(b);
	}
}

void	ft_instr_pb(t_stack *a, t_stack *b)
{
	t_element	elem;

	if (!ft_stack_empty(a))
	{
		elem = *(t_element *)ft_stack_top(a);
		ft_stack_push(b, &elem, sizeof(t_element));
		ft_stack_pop(a);
	}
}
