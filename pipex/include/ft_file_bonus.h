/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:28:11 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 16:16:19 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_BONUS_H
# define FT_FILE_BONUS_H

# include <stdbool.h>

# define PATH_HEREDOC	"/tmp/.heredoc"

int		ft_infile(const char *infile, const char *limiter, int n, bool heredoc);
int		ft_outfile(const char *outfile, bool heredoc);

#endif
