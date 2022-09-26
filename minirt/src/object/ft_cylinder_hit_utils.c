/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_hit_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:04:48 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 16:51:28 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_cylinder.h"

static bool	cy_cap_root(\
		const t_cylinder *cy, const t_ray *ray, t_hit_record *rec, double *root)
{
	t_vec3	cap_center;
	double	denom;
	double	numer;

	if (*root == CYL_CAP_TOP)
		cap_center = cy->cap_top;
	else
		cap_center = cy->cap_bot;
	numer = ft_vec_dot(ft_vec_sub(cap_center, ray->orig), cy->normal);
	denom = ft_vec_dot(ray->dir, cy->normal);
	*root = numer / denom;
	if (*root < rec->t_min || *root > rec->t_max)
		return (false);
	return (true);
}

bool	hit_cylinder_cap(\
		const t_cylinder *cy, const t_ray *ray, t_hit_record *rec, int mode)
{
	t_vec3	cap_center;
	double	root;
	double	diameter;

	if (mode == CYL_CAP_TOP)
		cap_center = cy->cap_top;
	else
		cap_center = cy->cap_bot;
	root = mode;
	if (!cy_cap_root(cy, ray, rec, &root))
		return (false);
	diameter = ft_vec_length(ft_vec_sub(cap_center, ft_ray_at(ray, root)));
	if (fabs(cy->radius) < fabs(diameter))
		return (false);
	rec->t = root;
	rec->p = ft_ray_at(ray, root);
	rec->t_max = rec->t;
	if (mode == CYL_CAP_TOP)
		rec->normal = cy->normal;
	else
		rec->normal = ft_vec_mul_t(cy->normal, -1.0);
	ft_ray_set_face_normal(ray, rec);
	rec->albedo = cy->albedo;
	return (true);
}
