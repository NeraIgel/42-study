/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_execute_instr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:31:39 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:44:14 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instr.h"
#include "ft_game.h"

static t_instrtbl	*ft_instr_lookup(t_instr instr)
{
	static t_instrtbl	tbl[MAX_INSTR + 1] = {\
		{"rra", ft_instr_rra}, {"rrb", ft_instr_rrb}, {"rrr", ft_instr_rrr}, \
		{"ra", ft_instr_ra}, {"rb", ft_instr_rb}, {"rr", ft_instr_rr}, \
		{"sa", ft_instr_sa}, {"sb", ft_instr_sb}, {"ss", ft_instr_ss}, \
		{"pa", ft_instr_pa}, {"pb", ft_instr_pb}, \
		{NULL, NULL}};
	t_instrtbl			*p;

	p = tbl;
	while (p->instr)
	{
		if (!ft_strcmp(instr, p->instr))
			return (p);
		p++;
	}
	return (NULL);
}

static void	ft_game_instr_execute(t_game *g, t_instr instr)
{
	t_instrtbl	*p;

	p = ft_instr_lookup(instr);
	if (!p)
		ft_game_error(g, ERR_GAME);
	p->ft(&(g->a), &(g->b));
}

void	ft_game_execute_instr(t_game *g)
{
	t_instr	instr;

	if (!ft_queue_empty(&(g->instr_queue)))
	{
		instr = (t_instr)ft_queue_front(&(g->instr_queue));
		ft_game_instr_execute(g, instr);
		ft_queue_pop(&(g->instr_queue));
	}
}
