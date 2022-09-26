/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:12:25 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 16:56:37 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scene.h"

bool	ft_is_scene_type(const char *type)
{
	return (ft_is_camera_type(type) \
			|| ft_is_light_type(type) \
			|| ft_is_ambient_type(type));
}

bool	ft_check_scene_initialized(const t_scene *scene)
{
	if (!(scene->camera.initialized))
		return (false);
	if (1U != ft_deque_size(&(scene->lights)))
		return (false);
	if (!(scene->ambient.initialized))
		return (false);
	return (true);
}

bool	ft_scene_setup(t_scene *scene, char *const *tbl)
{
	if (ft_is_camera_type(tbl[0]) \
			&& !ft_camera_setup(&(scene->camera), &(scene->canvas), tbl))
		return (false);
	else if (ft_is_light_type(tbl[0]) \
			&& !ft_lights_setup(&(scene->lights), tbl))
		return (false);
	else if (ft_is_ambient_type(tbl[0]) \
			&& !ft_ambient_setup(&(scene->ambient), tbl))
		return (false);
	return (true);
}

void	ft_set_scene_info(t_scene *scene)
{
	ft_set_camera_viewport(&(scene->camera), &(scene->canvas));
	ft_set_ambient_value(&(scene->ambient));
	ft_set_lights_value(&(scene->lights));
}
