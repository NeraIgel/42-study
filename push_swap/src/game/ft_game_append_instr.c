/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_append_instr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:25:53 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:44:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algo.h"
#include "ft_game.h"

static t_instr	*ft_instr_split(t_instr instr)
{
	return (ft_split(instr, ':'));
}

static void	ft_algo_setup(t_algo *info, size_t size)
{
	info->size = size;
	info->chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
}

static t_instr	ft_game_instr_fetch(t_game *g)
{
	static t_algo	info;

	if (!info.size)
		ft_algo_setup(&info, ft_stack_size(&(g->a)));
	return (ft_algo_sort(&(g->a), &(g->b), &info));
}

void	ft_game_append_instr(t_game *g)
{
	t_instr	instr;
	t_instr	*p;
	t_instr	*instrtbl;

	if (ft_queue_empty(&(g->instr_queue)))
	{
		instr = ft_game_instr_fetch(g);
		if (!instr)
			ft_game_error(g, ERR_GAME);
		instrtbl = ft_instr_split(instr);
		if (!instrtbl)
			ft_game_error(g, ERR_GAME);
		p = instrtbl;
		while (*p)
		{
			ft_queue_push(&(g->instr_queue), *p, ft_strlen(*p) + 1);
			free(*p);
			p++;
		}
		free(*p);
		free(instrtbl);
		free(instr);
	}
}
