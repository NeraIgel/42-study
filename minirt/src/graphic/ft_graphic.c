/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:53:48 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 21:01:43 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphic.h"

void	ft_graphic_init(t_graphic *g)
{
	ft_memset(&(g->scene), 0, sizeof(t_scene));
	ft_deque_create(&(g->scene.lights));
	ft_deque_create(&(g->objects));
}

void	ft_graphic_destroy(t_graphic *g)
{
	ft_objects_cleanup(&(g->objects));
	ft_deque_destroy(&(g->objects));
	ft_deque_destroy(&(g->scene.lights));
}

bool	ft_graphic_error(t_graphic *g, const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	ft_graphic_destroy(g);
	return (false);
}
