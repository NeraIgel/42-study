/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:01:47 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:43:24 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_elem.h"
#include "ft_game.h"

void	ft_game_init(t_game *g)
{
	ft_stack_init(&(g->a), ft_elem_compare, NULL);
	ft_stack_init(&(g->b), ft_elem_compare, NULL);
	ft_stack_init(&(g->input), ft_int_compare, NULL);
	ft_queue_init(&(g->instr_queue));
	ft_queue_init(&(g->print_queue));
}

void	ft_game_clear(t_game *g)
{
	ft_stack_clear(&(g->a));
	ft_stack_clear(&(g->b));
	ft_stack_clear(&(g->input));
	ft_queue_clear(&(g->instr_queue));
	ft_queue_clear(&(g->print_queue));
}

void	ft_game_error(t_game *g, char *errmsg)
{
	if (errmsg)
		ft_putendl_fd(errmsg, STDERR_FILENO);
	ft_game_clear(g);
	exit(EXIT_FAILURE);
}
