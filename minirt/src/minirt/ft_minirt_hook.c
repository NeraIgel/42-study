/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:12:09 by chpark            #+#    #+#             */
/*   Updated: 2022/09/26 15:12:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key_mac.h"
#include "ft_minirt.h"

static void	ft_minirt_hook4(t_minirt *rt, int keycode)
{
	if (rt->hook.mode == 4)
	{
		if (rt->hook.pl_index < 0)
			return ;
		else
		{
			ft_minirt_hook_pl(ft_check_type(&rt->graphic.objects, "pl", \
			rt->graphic.objects.size, rt->hook.pl_index), keycode, rt);
		}
	}
	else if (rt->hook.mode == 5)
	{
		if (rt->hook.cy_index < 0)
			return ;
		else
		{
			ft_minirt_hook_cy(ft_check_type(&rt->graphic.objects, "cy", \
			rt->graphic.objects.size, rt->hook.cy_index), keycode, rt);
		}
	}
	else
		return ;
}

void	ft_minirt_hook3(t_minirt *rt, int keycode)
{
	if (rt->hook.mode == 1)
		ft_minirt_hook_camera(&rt->graphic.scene.camera, keycode, rt);
	else if (rt->hook.mode == 2)
	{
		if (rt->graphic.scene.lights.size < 0)
			return ;
		else
		{
			ft_minirt_hook_light(ft_find_light(&rt->graphic.scene.lights, \
			rt->hook.lights_index), keycode, rt);
		}
	}
	else if (rt->hook.mode == 3)
	{
		if (rt->hook.sp_index < 0)
			return ;
		else
		{
			ft_minirt_hook_sp(ft_check_type(&rt->graphic.objects, "sp", \
			rt->graphic.objects.size, rt->hook.sp_index), keycode, rt);
		}
	}
	else
		ft_minirt_hook4(rt, keycode);
}

void	ft_minirt_hook2(t_minirt *rt, int keycode)
{
	if (keycode == K_NUM_4)
	{
		if (rt->hook.mode == 4)
			ft_minirt_hook_indexing(&rt->hook.pl_index, \
				&rt->hook.pl_size);
		else
			rt->hook.mode = 4;
	}
	if (keycode == K_NUM_5)
	{
		if (rt->hook.mode == 5)
			ft_minirt_hook_indexing(&rt->hook.cy_index, \
				&rt->hook.cy_size);
		else
			rt->hook.mode = 5;
	}
	else
		ft_minirt_hook3(rt, keycode);
}

void	ft_minirt_hook(t_minirt *rt, int keycode)
{
	if (keycode == K_NUM_1)
		rt->hook.mode = 1;
	if (keycode == K_NUM_2)
	{
		if (rt->hook.mode == 2)
			ft_minirt_hook_indexing(&rt->hook.lights_index, \
				&rt->graphic.scene.lights.size);
		else
			rt->hook.mode = 2;
	}
	if (keycode == K_NUM_3)
	{
		if (rt->hook.mode == 3)
			ft_minirt_hook_indexing(&rt->hook.sp_index, \
				&rt->hook.sp_size);
		else
			rt->hook.mode = 3;
	}
	else
		ft_minirt_hook2(rt, keycode);
}
