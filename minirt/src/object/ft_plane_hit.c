/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:37:36 by heha              #+#    #+#             */
/*   Updated: 2022/09/23 16:43:28 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_plane.h"

static bool	ft_hit_check(\
		const t_plane *pl, const t_ray *ray, t_hit_record *rec)
{
	float	numrator;
	float	denominator;
	float	t;

	denominator = ft_vec_dot(ray->dir, pl->normal);
	if (fabs(denominator) < EPSILON)
		return (false);
	numrator = ft_vec_dot(ft_vec_sub(pl->point, ray->orig), pl->normal);
	t = numrator / denominator;
	if (t < rec->t_min || rec->t_max <= t)
		return (false);
	rec->t = t;
	rec->p = ft_ray_at(ray, t);
	rec->normal = pl->normal;
	ft_ray_set_face_normal(ray, rec);
	rec->albedo = pl->albedo;
	return (true);
}

int	ft_plane_hit(const void *data, const t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;

	pl = (t_plane *)data;
	pl->albedo = ft_vec_div_t(pl->color, 255.0);
	return (ft_hit_check(pl, ray, rec));
}
