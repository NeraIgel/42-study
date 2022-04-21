/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:00:25 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:43:08 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_core_bonus.h"

int	main(int argc, char **argv)
{
	t_checker	checker;

	if (argc > 1)
	{
		ft_checker_init(&checker);
		ft_checker_setup(&checker, argc, argv);
		ft_checker_routine(&checker);
		ft_checker_clear(&checker);
	}
	return (EXIT_SUCCESS);
}
