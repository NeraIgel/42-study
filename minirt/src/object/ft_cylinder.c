/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:51:08 by heha              #+#    #+#             */
/*   Updated: 2022/09/21 18:51:17 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cylinder.h"

bool	ft_is_cylinder_type(const char *type)
{
	return (!ft_strcmp(type, "cy"));
}

bool	ft_cylinder_error(t_cylinder *cy, const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	if (cy)
		free(cy);
	return (false);
}
