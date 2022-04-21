/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:15:03 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:44:33 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_core.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 1)
	{
		ft_game_init(&game);
		ft_game_setup(&game, argc, argv);
		ft_game_routine(&game);
		ft_game_print(&game);
		ft_game_clear(&game);
	}
	return (EXIT_SUCCESS);
}
