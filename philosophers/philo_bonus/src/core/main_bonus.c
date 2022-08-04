/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:28:36 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 21:12:06 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_core_bonus.h"
#include "ft_monitor_bonus.h"

int	main(int argc, char *argv[])
{
	t_monitor	m;

	if (ft_args_check(argc, argv))
	{
		ft_monitor_init(&m);
		ft_monitor_setup(&m, argc, argv);
		ft_monitor_routine(&m);
		ft_monitor_destroy(&m);
		return (m.ret);
	}
	else
		return (EXIT_FAILURE);
}
