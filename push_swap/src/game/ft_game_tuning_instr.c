/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_tuning_instr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:56:46 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:44:06 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instr.h"
#include "ft_game.h"

void	ft_game_tuning_instr(t_game *g)
{
	t_instr	instr;

	if (!ft_queue_empty(&(g->instr_queue)))
	{
		instr = (t_instr)ft_queue_front(&(g->instr_queue));
		ft_queue_push(&(g->print_queue), instr, ft_strlen(instr) + 1);
	}
}
