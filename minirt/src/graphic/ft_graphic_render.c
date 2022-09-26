/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:54:23 by heha              #+#    #+#             */
/*   Updated: 2022/09/22 12:24:58 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_ray.h"
#include "ft_graphic.h"

static void	ft_write_color(t_img *img, int j, int i, const t_color3 *clr)
{
	const int	bytes_per_pixel = img->bits_per_pixel / CHAR_BIT;
	int			trgb;
	char		*dst;

	dst = img->data + (j * img->line_length + i * bytes_per_pixel);
	trgb = ft_trgb(0, 255.999 * clr->x, 255.999 * clr->y, 255.999 * clr->z);
	*(unsigned int *)dst = trgb;
}

void	ft_graphic_render(t_graphic *g, t_img *img)
{
	int			j;
	int			i;
	t_ray		ray;
	t_color3	color;

	ft_set_scene_info(&(g->scene));
	j = g->scene.canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < g->scene.canvas.width)
		{
			ray = ft_ray_primary(&(g->scene.camera), \
					(double)j / (g->scene.canvas.height - 1.0), \
					(double)i / (g->scene.canvas.width - 1.0));
			color = ft_ray_color(&ray, &(g->scene), &(g->objects));
			ft_write_color(img, g->scene.canvas.height - j - 1, i, &color);
			i++;
		}
		j--;
	}
}
