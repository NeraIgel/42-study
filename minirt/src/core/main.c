/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:10:21 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 13:10:32 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_core.h"
#include "ft_minirt.h"

int	main(int argc, char *argv[])
{
	t_minirt	rt;

	if (ft_args_check(argc, argv))
	{
		ft_minirt_create_window(&rt, argv[1]);
		ft_minirt_message_loop(&rt);
	}
	else
		return (EXIT_FAILURE);
}
