/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:32:47 by heha              #+#    #+#             */
/*   Updated: 2022/09/21 18:35:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_plane.h"

bool	ft_is_plane_type(const char *type)
{
	return (!ft_strcmp(type, "pl"));
}

bool	ft_plane_error(t_plane *pl, const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	if (pl)
		free(pl);
	return (false);
}
