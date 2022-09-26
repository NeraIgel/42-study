/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt_hook3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:58:16 by chpark            #+#    #+#             */
/*   Updated: 2022/09/22 18:58:18 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key_mac.h"
#include "ft_minirt.h"

void	ft_minirt_hook_light(t_light *light, int keycode, t_minirt *rt)
{
	if (0 <= keycode && keycode < 15)
		ft_minirt_hook_point(&light->orig, keycode, rt);
	else
		ft_minirt_hook_color(&light->color, keycode, rt);
}

void	ft_minirt_hook_color(t_color3 *color, int keycode, t_minirt	*rt)
{
	if (keycode == K_U)
		color->x += 25;
	if (keycode == K_I)
		color->x -= 25;
	if (keycode == K_O)
		color->y += 25;
	if (keycode == K_P)
		color->y -= 25;
	if (keycode == 33)
		color->z += 25;
	if (keycode == 30)
		color->z -= 25;
	if (30 <= keycode && keycode <= 35)
	{
		ft_color_range_check(color);
		rt->win.invalidate = true;
	}
}

static void	ft_minirt_hook_point2(t_point3 *point, int keycode, t_minirt *rt)
{
	if (keycode == K_E)
	{
		point->x += 1;
		point->y += 1;
	}
	if (keycode == K_Z)
	{
		point->x -= 1;
		point->y -= 1;
	}
	if (keycode == K_C)
	{
		point->x += 1;
		point->y -= 1;
	}
	if (keycode == K_S)
		point->z -= 1;
	if (keycode == K_F)
		point->z += 1;
	if (keycode == K_E || keycode == K_Z || keycode == K_C || \
		keycode == K_S || keycode == K_F)
		rt->win.invalidate = true;
}

void	ft_minirt_hook_point(t_point3 *point, int keycode, t_minirt	*rt)
{
	if (keycode == K_A)
		point->x -= 1;
	if (keycode == K_D)
		point->x += 1;
	if (keycode == K_W)
		point->y += 1;
	if (keycode == K_X)
		point->y -= 1;
	if (keycode == K_Q)
	{
		point->x -= 1;
		point->y += 1;
	}
	if (keycode == K_A || keycode == K_D || keycode == K_W || \
		keycode == K_Q || keycode == K_X)
		rt->win.invalidate = true;
	else
		ft_minirt_hook_point2(point, keycode, rt);
}
