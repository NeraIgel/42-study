/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt_hook2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:12:22 by chpark            #+#    #+#             */
/*   Updated: 2022/09/22 15:12:24 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key_mac.h"
#include "ft_minirt.h"

static void	ft_minirt_hook_vec(t_vec3 *vec, int keycode, t_minirt *rt)
{
	if (keycode == K_N)
		vec->x -= 0.1;
	if (keycode == K_M)
		vec->x += 0.1;
	if (keycode == 43)
		vec->y -= 0.1;
	if (keycode == 47)
		vec->y += 0.1;
	if (keycode == 44)
		vec->z -= 0.1;
	if (keycode == 39)
		vec->z += 0.1;
	if ((43 <= keycode && keycode <= 47) || keycode == 39)
	{
		ft_normalized_vec_range_check(vec);
		rt->win.invalidate = true;
	}
	else
		return ;
}

void	ft_minirt_hook_camera(t_camera *cam, int keycode, t_minirt	*rt)
{
	if (keycode == K_J)
	{
		if (cam->fov > 0)
			cam->fov -= 1;
		else
			return ;
	}
	if (keycode == K_K)
	{
		if (cam->fov < 180)
			cam->fov += 1;
		else
			return ;
	}
	if ((43 <= keycode && keycode <= 47) || keycode == 39)
		ft_minirt_hook_vec(&cam->dir, keycode, rt);
	if (keycode == K_J || keycode == K_K)
		rt->win.invalidate = true;
	if (0 <= keycode && keycode < 15)
		ft_minirt_hook_point(&cam->orig, keycode, rt);
	else
		return ;
}

void	ft_minirt_hook_sp(t_object *obj, int keycode, t_minirt *rt)
{
	t_sphere	*sp;

	sp = obj->data;
	if (keycode == K_J)
	{
		if (sp->diameter == 1)
			return ;
		else
			sp->diameter -= 1;
	}
	if (keycode == K_K)
		sp->diameter += 1;
	if (keycode == K_J || keycode == K_K)
		rt->win.invalidate = true;
	if (0 <= keycode && keycode < 15)
		ft_minirt_hook_point(&sp->center, keycode, rt);
	else
		ft_minirt_hook_color(&sp->color, keycode, rt);
}

void	ft_minirt_hook_pl(t_object *obj, int keycode, t_minirt *rt)
{
	t_plane	*pl;

	pl = obj->data;
	if ((43 <= keycode && keycode <= 47) || keycode == 39)
		ft_minirt_hook_vec(&pl->normal, keycode, rt);
	if (0 <= keycode && keycode < 15)
		ft_minirt_hook_point(&pl->point, keycode, rt);
	else
		ft_minirt_hook_color(&pl->color, keycode, rt);
}

void	ft_minirt_hook_cy(t_object *obj, int keycode, t_minirt *rt)
{
	t_cylinder	*cy;

	cy = obj->data;
	if (keycode == K_J)
	{
		if (cy->diameter == 1)
			return ;
		else
			cy->diameter -= 1;
	}
	if (keycode == K_K)
		cy->diameter += 1;
	if (keycode == K_L)
		cy->height -= 1;
	if (keycode == 41)
		cy->height += 1;
	if (keycode == K_J || keycode == K_K || keycode == K_L || keycode == 41)
		rt->win.invalidate = true;
	if (0 <= keycode && keycode < 15)
		ft_minirt_hook_point(&cy->point, keycode, rt);
	else
		ft_minirt_hook_color(&cy->color, keycode, rt);
	if ((43 <= keycode && keycode <= 47) || keycode == 39)
		ft_minirt_hook_vec(&cy->normal, keycode, rt);
}
