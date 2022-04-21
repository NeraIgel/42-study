/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:49:39 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:42:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instr.h"

void	ft_instr_ra(t_stack *a, t_stack *b)
{
	void	*notused;

	notused = b;
	ft_stack_rotate(a);
}

void	ft_instr_rb(t_stack *a, t_stack *b)
{
	void	*notused;

	notused = a;
	ft_stack_rotate(b);
}

void	ft_instr_rr(t_stack *a, t_stack *b)
{
	ft_stack_rotate(a);
	ft_stack_rotate(b);
}
