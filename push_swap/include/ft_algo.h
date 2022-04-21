/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:20:49 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:44:40 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGO_H
# define FT_ALGO_H

# include "ft_instr.h"

typedef struct s_algo
{
	size_t	size;
	size_t	chunk;
}	t_algo;

t_instr	ft_algo_sort(t_stack *a, t_stack *b, t_algo *info);
t_instr	ft_algo_sort_two(void);
t_instr	ft_algo_sort_three(t_stack *a);
t_instr	ft_algo_sort_simple(t_stack *a, t_stack *b, t_algo *info);
t_instr	ft_algo_sort_greedy(t_stack *a, t_stack *b, t_algo *info);

#endif
