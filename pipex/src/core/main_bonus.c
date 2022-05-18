/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:44:46 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:37:22 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_core_bonus.h"

int	main(int argc, char *argv[])
{
	const char	*errmsg = "\033[31;1mError:\033[0m Invalid number of arguments.";
	t_pipex		p;

	if (argc >= 5)
	{
		ft_pipex_init(&p);
		ft_pipex_setup(&p, argc, argv);
		ft_pipex_routine(&p);
		ft_pipex_clear(&p);
	}
	else
		ft_pipex_error(&p, errmsg);
	return (p.ret);
}
