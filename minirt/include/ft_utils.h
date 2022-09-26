/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:36:36 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 12:36:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdbool.h>
# include <stdlib.h>

void	ft_tblclear(char ***tbl);
int		ft_gnl_without_newline(int fd, char **line);

bool	ft_check_strtoi_iter(\
		const char *str, const int *limit, int *dst, size_t cnt);
bool	ft_check_strtod_iter(\
		const char *str, const double *limit, double *dst, size_t cnt);

#endif
