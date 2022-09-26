/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_phong_lighting_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:35:24 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 16:24:40 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_object.h"
#include "ft_ray.h"

static t_vec3	ft_reflect_dir(t_vec3 v, t_vec3 n)
{
	return (ft_vec_sub(v, ft_vec_mul_t(n, ft_vec_dot(v, n) * 2.0)));
}

t_color3	ft_get_specular(const t_ray *ray, const t_light *light, \
		t_vec3 light_dir, t_hit_record *rec)
{
	t_vec3	reflect_dir;
	t_vec3	view_dir;
	double	spec;
	double	ksn;
	double	ks;

	reflect_dir = ft_reflect_dir(ft_vec_mul_t(light_dir, -1.0), rec->normal);
	view_dir = ft_vec_unit(ft_vec_mul_t(ray->dir, -1.0));
	ksn = 34.0;
	ks = 1.0;
	spec = pow(fmax(ft_vec_dot(view_dir, reflect_dir), 0.0), ksn);
	return (ft_vec_mul_t(ft_vec_mul_t(light->value, ks * light->ratio), spec));
}

t_color3	ft_get_diffuse(const t_light *light, \
		t_vec3 light_dir, t_hit_record *rec)
{
	double	kd;

	kd = fmax(ft_vec_dot(rec->normal, light_dir), 0.0);
	return (ft_vec_mul_t(light->value, kd * light->ratio));
}

bool	ft_check_in_shadow(const t_hit_record *rec, \
		t_vec3 light_dir, t_deque *objects)
{
	double			light_len;
	t_ray			light_ray;
	t_hit_record	temp_rec;

	light_len = ft_vec_length(light_dir);
	light_ray = ft_ray(ft_vec_add(\
				rec->p, ft_vec_mul_t(rec->normal, EPSILON)), light_dir);
	ft_memset(&temp_rec, 0, sizeof(t_hit_record));
	temp_rec.t_min = EPSILON;
	temp_rec.t_max = light_len;
	return (ft_objects_hit(objects, &light_ray, &temp_rec));
}
