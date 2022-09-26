/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_viewport.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:51:52 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 17:02:33 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_camera.h"

static double	ft_fov2rad(int fov)
{
	return (fov * (M_PI / (double)FOV_LIMIT));
}

static t_vec3	ft_dir(t_vec3 dir)
{
	if (dir.x == 0.0 && dir.y != 0.0 && dir.z == 0.0)
		return (ft_vec(0.0, dir.y, 1e-6));
	else
		return (ft_vec(0.0, 1.0, 0.0));
}

void	ft_set_camera_viewport(t_camera *cam, const t_canvas *cav)
{
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	cam->focal_length = tan(ft_fov2rad(cam->fov) / 2.0);
	cam->viewport_height = cam->focal_length * 2.0;
	cam->viewport_width = cav->aspect_ratio * cam->viewport_height;
	w = ft_vec_unit(ft_vec_mul_t(cam->dir, -1.0));
	u = ft_vec_unit(ft_vec_cross(ft_dir(cam->dir), w));
	v = ft_vec_cross(w, u);
	cam->horizontal = ft_vec_mul_t(u, cam->viewport_width);
	cam->vertical = ft_vec_mul_t(v, cam->viewport_height);
	cam->lower_left_corner = ft_vec(\
			cam->orig.x + (-cam->horizontal.x / 2) + (-cam->vertical.x / 2) + \
			(-w.x),
			cam->orig.y + (-cam->horizontal.y / 2) + (-cam->vertical.y / 2) + \
			(-w.y),
			cam->orig.z + (-cam->horizontal.z / 2) + (-cam->vertical.z / 2) + \
			(-w.z));
}
