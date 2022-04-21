/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_sort_common.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:01:20 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:49:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algo.h"

static void	ft_flag_setup(t_stack *a, t_stack *b, t_algo *info, int *flag)
{
	const size_t	a_size = ft_stack_size(a);
	const size_t	b_size = ft_stack_size(b);
	const size_t	a_minidx = ft_stack_get_minidx(a);
	const size_t	a_maxidx = ft_stack_get_maxidx(a);

	if (a_size == info->size && b_size == 0)
		*flag = 0;
	if (*flag == 0 && a_size == 3 && b_size == info->size - 3)
		*flag = 1;
	if (*flag == 1 && a_minidx == 0 && a_maxidx == 2)
		*flag = 2;
}

static t_instr	ft_algo_sort_pre(t_stack *a, t_stack *b)
{
	const size_t	a_min_idx = ft_stack_get_minidx(a);
	const size_t	a_max_idx = ft_stack_get_maxidx(a);

	if (ft_stack_empty(b))
	{
		if (a_max_idx == 0)
			return (ft_strdup("pb"));
		else if (a_max_idx <= 2)
			return (ft_strdup("ra"));
		else
			return (ft_strdup("rra"));
	}
	else
	{
		if (a_min_idx == 0)
			return (ft_strdup("pb"));
		else if (a_min_idx <= 2)
			return (ft_strdup("ra"));
		else
			return (ft_strdup("rra"));
	}
}

t_instr	ft_algo_sort_two(void)
{
	return (ft_strdup("sa"));
}

t_instr	ft_algo_sort_three(t_stack *a)
{
	const size_t	min_idx = ft_stack_get_minidx(a);
	const size_t	max_idx = ft_stack_get_maxidx(a);

	if (min_idx == 0)
		return (ft_strdup("sa:ra"));
	else if (min_idx == 1 && max_idx == 2)
		return (ft_strdup("sa"));
	else if (min_idx == 1 && max_idx == 0)
		return (ft_strdup("ra"));
	else if (min_idx == 2 && max_idx == 1)
		return (ft_strdup("rra"));
	else
		return (ft_strdup("sa:rra"));
}

t_instr	ft_algo_sort_simple(t_stack *a, t_stack *b, t_algo *info)
{
	static int	flag;

	ft_flag_setup(a, b, info, &flag);
	if (flag == 0)
		return (ft_algo_sort_pre(a, b));
	else if (flag == 1)
		return (ft_algo_sort_three(a));
	else
	{
		if (info->size == 4)
			return (ft_strdup("pa:ra"));
		else
			return (ft_strdup("pa:pa:ra"));
	}
}
