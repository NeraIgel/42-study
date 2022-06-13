/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:23:25 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 12:52:20 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_fdf.h"
#include "ft_events.h"
#include "ft_key_macos.h"

static int	ft_destroy_hook(t_fdf *f)
{
	ft_fdf_exit(f, MSG_QUIT);
	return (0);
}

static int	ft_key_hook(int keycode, t_fdf *f)
{
	if (K_ESC == keycode)
		ft_fdf_exit(f, MSG_ESC);
	return (0);
}

static int	ft_loop_hook(t_fdf *f)
{
	const int	resolution = f->cam.height * f->img.line_length;

	if (f->cam.invalidate)
	{
		f->cam.invalidate = false;
		ft_memset(f->img.data, 0, resolution);
		ft_graphic_draw(&(f->graphic), &(f->cam), &(f->img));
		mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	}
	return (0);
}

void	ft_fdf_routine(t_fdf *f)
{
	mlx_hook(f->win, X_EVENT_DESTROY, 1L << X_MASK_DESTROY, ft_destroy_hook, f);
	mlx_hook(f->win, X_EVENT_KEY_PRESS, 1L << X_MASK_KEY_PRESS, ft_key_hook, f);
	mlx_loop_hook(f->mlx, ft_loop_hook, f);
	mlx_loop(f->mlx);
}
