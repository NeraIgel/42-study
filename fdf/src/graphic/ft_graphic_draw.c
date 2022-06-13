/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:37:13 by heha              #+#    #+#             */
/*   Updated: 2022/06/12 19:01:30 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <limits.h>
#include "ft_graphic.h"

static void	ft_line_init(t_line *params, t_pos start, t_pos end)
{
	params->sign_y = -1;
	if (start.y < end.y)
		params->sign_y = 1;
	params->sign_x = -1;
	if (start.x < end.x)
		params->sign_x = 1;
	params->delta_y = fabs((double)end.y - start.y);
	params->delta_x = fabs((double)end.x - start.x);
	params->offset = params->delta_x - params->delta_y;
	params->error = 0;
}

static void	ft_draw_pixel(t_img *img, const t_cam *cam, t_pos cur)
{
	const int	bytes_per_pixel = img->bits_per_pixel / CHAR_BIT;
	char		*dst;

	if (cur.y >= 0 && cur.y < cam->height && cur.x >= 0 && cur.x < cam->width)
	{
		dst = img->data + (cur.y * img->line_length + cur.x * bytes_per_pixel);
		*(unsigned int *)dst = cur.color;
	}
}

static void	ft_draw_line(t_img *img, const t_cam *cam, t_pos start, t_pos end)
{
	t_pos	cur;
	t_line	params;

	ft_line_init(&params, start, end);
	cur = start;
	while (cur.y != end.y || cur.x != end.x)
	{
		ft_draw_pixel(img, cam, cur);
		params.error = params.offset * 2;
		if (params.error > -params.delta_y)
		{
			params.offset -= params.delta_y;
			cur.x += params.sign_x;
		}
		if (params.error < params.delta_x)
		{
			params.offset += params.delta_x;
			cur.y += params.sign_y;
		}
	}
	ft_draw_pixel(img, cam, cur);
}

void	ft_graphic_draw(const t_graphic *g, const t_cam *cam, t_img *img)
{
	int		y;
	int		x;

	y = 0;
	while (y < g->row)
	{
		x = 0;
		while (x < g->col)
		{
			if (y < g->row - 1)
				ft_draw_line(img, cam, \
						ft_transpos(g->grid[y][x], g->row, g->col, cam), \
						ft_transpos(g->grid[y + 1][x], g->row, g->col, cam));
			if (x < g->col - 1)
				ft_draw_line(img, cam, \
						ft_transpos(g->grid[y][x], g->row, g->col, cam), \
						ft_transpos(g->grid[y][x + 1], g->row, g->col, cam));
			x++;
		}
		y++;
	}
}
