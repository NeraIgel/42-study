/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:56:08 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:43:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# include "ft_stack.h"
# include "ft_queue.h"

# define ERR_GAME	"\033[31;1mError\033[0m"

typedef struct s_game
{
	t_stack	a;
	t_stack	b;
	t_stack	input;
	t_queue	instr_queue;
	t_queue	print_queue;
}	t_game;

void	ft_game_init(t_game *g);
void	ft_game_clear(t_game *g);
void	ft_game_error(t_game *g, char *errmsg);
void	ft_game_setup(t_game *g, int argc, char **argv);
void	ft_game_routine(t_game *g);
void	ft_game_append_instr(t_game *g);
void	ft_game_tuning_instr(t_game *g);
void	ft_game_execute_instr(t_game *g);
void	ft_game_print(t_game *g);

#endif
