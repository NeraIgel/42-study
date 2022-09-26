/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt_create_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:45:47 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 15:57:13 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_minirt.h"

static void	ft_minirt_init(t_minirt *rt)
{
	rt->mlx = NULL;
	ft_memset(&(rt->win), 0, sizeof(t_win));
	ft_memset(&(rt->img), 0, sizeof(t_img));
	ft_memset(&(rt->hook), 0, sizeof(t_hook));
	ft_graphic_init(&(rt->graphic));
}

static void	ft_minirt_graphic_setup(t_minirt *rt, const char *scenefile)
{
	if (!ft_graphic_setup(&(rt->graphic), scenefile))
		ft_minirt_error(rt, NULL);
}

static void	ft_minirt_window_hook_setup(t_minirt *rt)
{
	size_t		i;
	t_object	*obj;

	rt->win.width = rt->graphic.scene.canvas.width;
	rt->win.height = rt->graphic.scene.canvas.height;
	rt->win.title = "miniRT";
	rt->win.invalidate = true;
	i = 0U;
	while (i < ft_deque_size(&(rt->graphic.objects)))
	{
		obj = (t_object *)ft_deque_at(&(rt->graphic.objects), i);
		if (!ft_strcmp(obj->type, "sp"))
			rt->hook.sp_size++;
		else if (!ft_strcmp(obj->type, "pl"))
			rt->hook.pl_size++;
		else if (!ft_strcmp(obj->type, "cy"))
			rt->hook.cy_size++;
		i++;
	}
	rt->hook.lights_size = ft_deque_size(&(rt->graphic.scene.lights));
}

static void	ft_minirt_mlx_setup(t_minirt *rt)
{
	rt->mlx = mlx_init();
	if (!(rt->mlx))
		ft_minirt_error(rt, "Can't init mlx.");
	rt->win.win = mlx_new_window(rt->mlx, \
			rt->win.width, rt->win.height, rt->win.title);
	if (!(rt->win.win))
		ft_minirt_error(rt, "Can't get window surface.");
	rt->img.img = mlx_new_image(rt->mlx, rt->win.width, rt->win.height);
	if (!(rt->img.img))
		ft_minirt_error(rt, "Can't get image surface.");
	rt->img.data = mlx_get_data_addr(rt->img.img, \
			&rt->img.bits_per_pixel, &rt->img.line_length, &rt->img.endian);
	if (!(rt->img.data))
		ft_minirt_error(rt, "Can't get image data.");
}

void	ft_minirt_create_window(t_minirt *rt, const char *scenefile)
{
	ft_minirt_init(rt);
	ft_minirt_graphic_setup(rt, scenefile);
	ft_minirt_window_hook_setup(rt);
	ft_minirt_mlx_setup(rt);
}
