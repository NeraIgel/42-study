/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:33:05 by heha              #+#    #+#             */
/*   Updated: 2022/09/21 14:54:59 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

t_ray	ft_ray(t_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = ft_vec_unit(dir);
	return (ray);
}

t_ray	ft_ray_primary(const t_camera *camera, double v, double u)
{
	t_ray	ray;

	ray.orig = camera->orig;
	ray.dir = ft_vec_unit(ft_vec(\
			camera->lower_left_corner.x + u * camera->horizontal.x + \
			v * camera->vertical.x - camera->orig.x, \
			camera->lower_left_corner.y + u * camera->horizontal.y + \
			v * camera->vertical.y - camera->orig.y, \
			camera->lower_left_corner.z + u * camera->horizontal.z + \
			v * camera->vertical.z - camera->orig.z));
	return (ray);
}

t_point3	ft_ray_at(const t_ray *ray, double t)
{
	t_point3	point;

	point.x = ray->orig.x + ray->dir.x * t;
	point.y = ray->orig.y + ray->dir.y * t;
	point.z = ray->orig.z + ray->dir.z * t;
	return (point);
}

void	ft_ray_set_face_normal(const t_ray *ray, t_hit_record *rec)
{
	rec->front_face = ft_vec_dot(ray->dir, rec->normal) < 0.0;
	if (!(rec->front_face))
		rec->normal = ft_vec(-rec->normal.x, -rec->normal.y, -rec->normal.z);
}
