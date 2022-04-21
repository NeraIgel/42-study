/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:03:04 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:43:36 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

static bool	ft_game_complete(t_game *g)
{
	if (!ft_stack_check_sort(&(g->a)))
		return (false);
	if (!ft_stack_empty(&(g->b)))
		return (false);
	return (true);
}

void	ft_game_routine(t_game *g)
{
	while (!ft_game_complete(g))
	{
		ft_game_append_instr(g);
		ft_game_tuning_instr(g);
		ft_game_execute_instr(g);
	}
}
