/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:23:28 by heha              #+#    #+#             */
/*   Updated: 2022/09/23 17:56:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAY_H
# define FT_RAY_H

# include "ft_scene.h"

# define EPSILON	1e-6

enum e_light
{
	DIRECT_LIGHT,
	POINT_LIGHT,
	SPOT_LIGHT
};

typedef struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
}	t_ray;

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		t;
	double		t_min;
	double		t_max;
	bool		front_face;
	t_color3	albedo;
}	t_hit_record;

typedef struct s_phong
{
	const t_ray		*ray;
	t_color3		ambient;
	t_deque			*objects;
	t_hit_record	*rec;
}	t_phong;

t_ray		ft_ray(t_point3 orig, t_vec3 dir);
t_ray		ft_ray_primary(const t_camera *camera, double v, double u);

t_point3	ft_ray_at(const t_ray *ray, double t);
void		ft_ray_set_face_normal(const t_ray *ray, t_hit_record *rec);

t_color3	ft_ray_color(const t_ray *ray, t_scene *scene, t_deque *objects);

t_color3	ft_ray_phong_lighting(const t_ray *ray, \
		t_scene *scene, t_deque *objects, t_hit_record *rec);
t_color3	ft_get_specular(const t_ray *ray, const t_light *light, \
		t_vec3 light_dir, t_hit_record *rec);
t_color3	ft_get_diffuse(const t_light *light, \
		t_vec3 light_dir, t_hit_record *rec);
bool		ft_check_in_shadow(const t_hit_record *rec, \
		t_vec3 light_dir, t_deque *objects);

#endif
