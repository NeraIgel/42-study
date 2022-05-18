/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:51:16 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:16:29 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

typedef struct s_pipex
{
	int		ret;
	int		size;
	char	*infile;
	char	*outfile;
	char	**command;
	char	**environ;
}	t_pipex;

void	ft_pipex_init(t_pipex *p);
void	ft_pipex_clear(t_pipex *p);
void	ft_pipex_error(t_pipex *p, const char *errmsg);
void	ft_pipex_setup(t_pipex *p, int argc, char *argv[]);
void	ft_pipex_routine(t_pipex *p);

#endif
