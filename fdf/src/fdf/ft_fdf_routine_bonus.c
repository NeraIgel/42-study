/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_routine_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:17:18 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 12:52:38 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_fdf_bonus.h"
#include "ft_enums_bonus.h"
#include "ft_events.h"
#include "ft_key_macos.h"

static t_hooktbl	*ft_hook_lookup(int keycode)
{
	static t_hooktbl	tbl[MAX_HOOK + 1] = {\
		{K_NP_1, ft_hook_type}, {K_NP_2, ft_hook_type}, \
		{K_NP_MIN, ft_hook_zoom}, {K_NP_PLU, ft_hook_zoom}, \
		{K_PG_U, ft_hook_depth}, {K_PG_D, ft_hook_depth}, \
		{K_AR_L, ft_hook_offset}, {K_AR_R, ft_hook_offset}, \
		{K_AR_U, ft_hook_offset}, {K_AR_D, ft_hook_offset}, \
		{K_X, ft_hook_rotate}, {K_W, ft_hook_rotate}, \
		{K_A, ft_hook_rotate}, {K_D, ft_hook_rotate}, \
		{K_Q, ft_hook_rotate}, {K_C, ft_hook_rotate}, \
		{-1, NULL}};
	t_hooktbl			*p;

	p = tbl;
	while (p->key >= 0)
	{
		if (keycode == p->key)
			return (p);
		p++;
	}
	return (NULL);
}

static int	ft_destroy_hook(t_fdf *f)
{
	ft_fdf_exit(f, MSG_QUIT);
	return (0);
}

static int	ft_key_hook(int keycode, t_fdf *f)
{
	t_hooktbl	*p;

	if (K_ESC == keycode)
		ft_fdf_exit(f, MSG_ESC);
	else
	{
		p = ft_hook_lookup(keycode);
		if (p)
			p->ft(&(f->cam), keycode);
	}
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
