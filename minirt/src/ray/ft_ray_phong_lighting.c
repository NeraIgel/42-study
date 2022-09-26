/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_phong_lighting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:38:30 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 16:23:11 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_ray.h"

static t_phong	ft_phong(const t_ray *ray, \
		t_scene *scene, t_deque *objects, t_hit_record *rec)
{
	t_phong	phong;

	phong.ray = ray;
	phong.ambient = scene->ambient.value;
	phong.objects = objects;
	phong.rec = rec;
	return (phong);
}

static t_color3	ft_get_point_light(const t_light *light, t_phong *phong)
{
	t_vec3		light_dir;
	t_color3	diffuse;
	t_color3	specular;

	light_dir = ft_vec_sub(light->orig, phong->rec->p);
	if (ft_check_in_shadow(phong->rec, light_dir, phong->objects))
		return (ft_color(0, 0, 0));
	light_dir = ft_vec_unit(light_dir);
	diffuse = ft_get_diffuse(light, light_dir, phong->rec);
	specular = ft_get_specular(phong->ray, light, light_dir, phong->rec);
	return (ft_vec_add(diffuse, specular));
}

t_color3	ft_ray_phong_lighting(const t_ray *ray, \
		t_scene *scene, t_deque *objects, t_hit_record *rec)
{
	size_t		i;
	t_phong		phong;
	t_light		*light;
	t_color3	light_val;

	i = 0U;
	light_val = ft_color(0, 0, 0);
	if (rec->t_max > INFINITY - 1.0)
		return (ft_color(0, 0, 0));
	while (i < ft_deque_size(&(scene->lights)))
	{
		phong = ft_phong(ray, scene, objects, rec);
		light = (t_light *)ft_deque_at(&(scene->lights), i);
		light_val = ft_vec_add(light_val, ft_get_point_light(light, &phong));
		i++;
	}
	light_val = ft_vec_add(light_val, scene->ambient.value);
	return (ft_vec_min(ft_vec_mul(\
					light_val, rec->albedo), ft_color(1, 1, 1)));
}
