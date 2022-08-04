/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:46:44 by heha              #+#    #+#             */
/*   Updated: 2022/07/25 13:46:48 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_core.h"
#include "ft_monitor.h"

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
