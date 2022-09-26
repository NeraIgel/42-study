/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:00:13 by heha              #+#    #+#             */
/*   Updated: 2022/09/21 16:00:22 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sphere.h"

bool	ft_is_sphere_type(const char *type)
{
	return (!ft_strcmp(type, "sp"));
}

bool	ft_sphere_error(t_sphere *sp, const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	if (sp)
		free(sp);
	return (false);
}
