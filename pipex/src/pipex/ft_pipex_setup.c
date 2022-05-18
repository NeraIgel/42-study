/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:59:28 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:16:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_pipex.h"

static void	ft_pipex_save_data(t_pipex *p, int argc, char *argv[])
{
	extern char	**environ;

	p->size = argc - 3;
	p->infile = argv[1];
	p->outfile = argv[argc - 1];
	p->command = argv + 2;
	p->environ = environ;
}

void	ft_pipex_setup(t_pipex *p, int argc, char *argv[])
{
	ft_pipex_save_data(p, argc, argv);
}
