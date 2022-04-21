/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:49:57 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:42:18 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instr.h"

void	ft_instr_rra(t_stack *a, t_stack *b)
{
	void	*notused;

	notused = b;
	ft_stack_reverse_rotate(a);
}

void	ft_instr_rrb(t_stack *a, t_stack *b)
{
	void	*notused;

	notused = a;
	ft_stack_reverse_rotate(b);
}

void	ft_instr_rrr(t_stack *a, t_stack *b)
{
	ft_stack_reverse_rotate(a);
	ft_stack_reverse_rotate(b);
}
