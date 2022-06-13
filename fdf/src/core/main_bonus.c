/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:14:58 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 11:38:50 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_core_bonus.h"

int	main(int argc, char *argv[])
{
	const char	*errmsg = "\033[31;1mError:\033[0m Invalid number of arguments.";
	t_fdf		f;

	ft_fdf_init(&f);
	if (argc == 2)
	{
		ft_fdf_setup(&f, argv);
		ft_fdf_routine(&f);
	}
	else
		ft_fdf_error(&f, errmsg);
	return (EXIT_SUCCESS);
}
