/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:10:23 by heha              #+#    #+#             */
/*   Updated: 2022/09/23 13:13:39 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_sphere.h"

static double	ft_get_discriminant(\
		const t_sphere *sp, const t_ray *ray, double *a, double *half_b)
{
	t_vec3	oc;
	double	c;

	oc = ft_vec_sub(ray->orig, sp->center);
	*a = ft_vec_length_squared(ray->dir);
	*half_b = ft_vec_dot(oc, ray->dir);
	c = ft_vec_length_squared(oc) - sp->radius * sp->radius;
	return (*half_b * *half_b - *a * c);
}

static void	ft_update_hit_record(\
		const t_sphere *sp, const t_ray *ray, t_hit_record *rec, double t)
{
	rec->t = t;
	rec->p = ft_ray_at(ray, t);
	rec->normal = ft_vec_div_t(\
			ft_vec_sub(rec->p, sp->center), sp->radius);
	ft_ray_set_face_normal(ray, rec);
	rec->albedo = sp->albedo;
}

static bool	ft_hit_check(\
		const t_sphere *sp, const t_ray *ray, t_hit_record *rec)
{
	double	a;
	double	half_b;
	double	discriminant;
	double	sqrtd;
	double	root;

	discriminant = ft_get_discriminant(sp, ray, &a, &half_b);
	if (discriminant < EPSILON)
		return (false);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->t_min || root > rec->t_max)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->t_min || root > rec->t_max)
			return (false);
	}
	ft_update_hit_record(sp, ray, rec, root);
	return (true);
}

int	ft_sphere_hit(const void *data, const t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;

	sp = (t_sphere *)data;
	sp->radius = sp->diameter / 2.0;
	sp->albedo = ft_vec_div_t(sp->color, 255.0);
	return (ft_hit_check(sp, ray, rec));
}
