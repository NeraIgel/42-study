/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:52:36 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:37:45 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H

# include <stdbool.h>

typedef struct s_pipex
{
	int		ret;
	int		size;
	bool	heredoc;
	char	*limiter;
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
