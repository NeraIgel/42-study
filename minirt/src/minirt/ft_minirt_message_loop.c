/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt_message_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:45:58 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 13:46:09 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_minirt.h"
#include "ft_key_mac.h"
#include "ft_mlx_events.h"

static int	ft_destroy_hook(t_minirt *rt)
{
	ft_minirt_exit(rt);
	return (0);
}

static int	ft_key_hook(int keycode, t_minirt *rt)
{
	if (K_ESC == keycode)
		ft_minirt_exit(rt);
	else
		ft_minirt_hook(rt, keycode);
	return (0);
}

static int	ft_loop_hook(t_minirt *rt)
{
	if (rt->win.invalidate)
	{
		rt->win.invalidate = false;
		ft_graphic_render(&(rt->graphic), &(rt->img));
		mlx_put_image_to_window(rt->mlx, rt->win.win, rt->img.img, 0, 0);
	}
	return (0);
}

void	ft_minirt_message_loop(t_minirt *rt)
{
	mlx_hook(rt->win.win, \
			X_EVENT_DESTROY, 1L << X_MASK_DESTROY, ft_destroy_hook, rt);
	mlx_hook(rt->win.win, \
			X_EVENT_KEY_PRESS, 1L << X_MASK_KEY_PRESS, ft_key_hook, rt);
	mlx_loop_hook(rt->mlx, ft_loop_hook, rt);
	mlx_loop(rt->mlx);
}
