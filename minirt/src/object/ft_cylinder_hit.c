/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_hit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:56:49 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 16:51:19 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_cylinder.h"

static bool	cy_side_root(\
		const t_cylinder *cy, const t_ray *ray, t_hit_record *rec, double *root)
{
	double		a;
	double		half_b;
	double		discriminant;
	t_vec3		oc;
	double		c;

	oc = ft_vec_sub(ray->orig, cy->point);
	a = ft_vec_length_squared(ft_vec_cross(ray->dir, cy->normal));
	half_b = ft_vec_dot(ft_vec_cross(ray->dir, cy->normal), \
		ft_vec_cross(oc, cy->normal));
	c = ft_vec_length_squared(ft_vec_cross(oc, cy->normal)) \
		- pow(cy->diameter / 2.0, 2.0);
	discriminant = half_b * half_b - a * c;
	if (discriminant < EPSILON)
		return (false);
	*root = (-half_b - sqrt(discriminant)) / a;
	if (*root < rec->t_min || *root > rec->t_max)
	{
		*root = (-half_b + sqrt(discriminant)) / a;
		if (*root < rec->t_min || *root > rec->t_max)
			return (false);
	}
	return (true);
}

static bool	cy_boundary(const t_cylinder *cy, t_vec3 at)
{
	double	hit_height;
	double	max_height;

	hit_height = ft_vec_dot(ft_vec_sub(at, cy->point), cy->normal);
	max_height = cy->height / 2.0;
	if (fabs(hit_height) > max_height)
		return (false);
	return (true);
}

static t_vec3	cy_norm(const t_cylinder *cy, t_vec3 at)
{
	t_vec3	norm;
	t_vec3	tmp;

	tmp = ft_vec_sub(at, cy->point);
	norm = ft_vec_sub(tmp, \
			ft_vec_mul_t(cy->normal, ft_vec_dot(cy->normal, tmp)));
	return (ft_vec_unit(norm));
}

static bool	hit_cylinder_side(\
		const t_cylinder *cy, const t_ray *ray, t_hit_record *rec)
{
	double		root;

	if (!cy_side_root(cy, ray, rec, &root))
		return (false);
	if (!cy_boundary(cy, ft_ray_at(ray, root)))
		return (false);
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->normal = cy_norm(cy, rec->p);
	ft_ray_set_face_normal(ray, rec);
	rec->albedo = cy->albedo;
	return (true);
}

int	ft_cylinder_hit(const void *data, const t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	int			result;

	cy = (t_cylinder *)data;
	cy->radius = cy->diameter / 2.0;
	cy->normal = ft_vec_unit(cy->normal);
	cy->albedo = ft_vec_div_t(cy->color, 255.0);
	cy->cap_top = ft_vec_add(cy->point, \
		ft_vec_mul_t(cy->normal, cy->height / 2.0));
	cy->cap_bot = ft_vec_add(cy->point, \
		ft_vec_mul_t(cy->normal, -(cy->height / 2.0)));
	result = 0;
	result += hit_cylinder_cap(cy, ray, rec, CYL_CAP_TOP);
	result += hit_cylinder_cap(cy, ray, rec, CYL_CAP_BOT);
	result += hit_cylinder_side(cy, ray, rec);
	return (result);
}
