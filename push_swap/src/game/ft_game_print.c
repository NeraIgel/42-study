/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:09:29 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:44:18 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instr.h"
#include "ft_game.h"

static void	ft_instr_print(void *content)
{
	ft_putendl_fd((t_instr)content, STDOUT_FILENO);
}

void	ft_game_print(t_game *g)
{
	ft_queue_iter(&(g->print_queue), ft_instr_print);
}
