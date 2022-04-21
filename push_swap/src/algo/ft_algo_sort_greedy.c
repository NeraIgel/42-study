/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_sort_greedy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:23:17 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:49:10 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_elem.h"
#include "ft_algo.h"

static t_instr	ft_push_a_to_b(t_stack *a, t_algo *info)
{
	static t_element	num;
	t_element			top;

	top = *(t_element *)ft_stack_top(a);
	if (top <= num)
	{
		num++;
		return (ft_strdup("pb"));
	}
	else if (num < top && top <= num + info->chunk)
	{
		num++;
		return (ft_strdup("pb:rb"));
	}
	else
		return (ft_strdup("ra"));
}

static t_instr	ft_push_b_to_a(t_stack *b)
{
	size_t	size;
	size_t	max_idx;

	max_idx = ft_stack_get_maxidx(b);
	if (max_idx != 0)
	{
		size = ft_stack_size(b);
		if (max_idx <= size / 2)
			return (ft_strdup("rb"));
		else
			return (ft_strdup("rrb"));
	}
	else
		return (ft_strdup("pa"));
}

static void	ft_trigger_setup(t_stack *b, t_algo *info, bool *reverse_trigger)
{
	if (ft_stack_empty(b))
		*reverse_trigger = false;
	else if (ft_stack_size(b) == info->size)
		*reverse_trigger = true;
}

t_instr	ft_algo_sort_greedy(t_stack *a, t_stack *b, t_algo *info)
{
	static bool	reverse_trigger;

	ft_trigger_setup(b, info, &reverse_trigger);
	if (!reverse_trigger)
		return (ft_push_a_to_b(a, info));
	else
		return (ft_push_b_to_a(b));
}
