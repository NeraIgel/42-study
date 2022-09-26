/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:38:55 by heha              #+#    #+#             */
/*   Updated: 2022/09/21 19:39:09 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_camera.h"

bool	ft_is_camera_type(const char *type)
{
	return (!ft_strcmp(type, "C"));
}

bool	ft_camera_error(const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	return (false);
}
