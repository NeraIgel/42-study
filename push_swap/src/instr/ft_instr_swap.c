/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:48:40 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:42:09 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instr.h"

void	ft_instr_sa(t_stack *a, t_stack *b)
{
	void	*notused;

	notused = b;
	ft_stack_swap(a);
}

void	ft_instr_sb(t_stack *a, t_stack *b)
{
	void	*notused;

	notused = a;
	ft_stack_swap(b);
}

void	ft_instr_ss(t_stack *a, t_stack *b)
{
	ft_stack_swap(a);
	ft_stack_swap(b);
}
