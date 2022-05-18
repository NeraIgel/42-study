/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_setup_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:58:37 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:44:24 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_pipex_bonus.h"

static void	ft_pipex_save_data(t_pipex *p, int argc, char *argv[])
{
	extern char	**environ;
	int			offset;

	offset = 0;
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		offset = 1;
		p->heredoc = true;
		p->limiter = argv[2];
	}
	else
		p->infile = argv[1];
	p->size = argc - 3 - offset;
	p->outfile = argv[argc - 1];
	p->command = argv + 2 + offset;
	p->environ = environ;
}

void	ft_pipex_setup(t_pipex *p, int argc, char *argv[])
{
	ft_pipex_save_data(p, argc, argv);
}
