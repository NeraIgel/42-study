/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:32:00 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:45:08 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algo.h"

t_instr	ft_algo_sort(t_stack *a, t_stack *b, t_algo *info)
{
	if (info->size == 2)
		return (ft_algo_sort_two());
	else if (info->size == 3)
		return (ft_algo_sort_three(a));
	else if (info->size <= 5)
		return (ft_algo_sort_simple(a, b, info));
	else
		return (ft_algo_sort_greedy(a, b, info));
}
