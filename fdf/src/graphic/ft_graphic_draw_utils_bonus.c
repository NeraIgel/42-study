/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_draw_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:20:44 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 11:40:36 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_enums_bonus.h"
#include "ft_structs_bonus.h"

static void	ft_rotate(t_pos *new, double alpha, double beta, double gamma)
{
	t_pos	old;

	old = *new;
	new->y = old.y * cos(alpha) + old.z * sin(alpha);
	new->z = -old.y * sin(alpha) + old.z * cos(alpha);
	new->x = old.x * cos(beta) + new->z * sin(beta);
	new->z = -old.x * sin(beta) + new->z * cos(beta);
	old = *new;
	new->x = old.x * cos(gamma) - old.y * sin(gamma);
	new->y = old.x * sin(gamma) + old.y * cos(gamma);
}

static void	ft_isometric_projection(t_pos *new)
{
	t_pos	old;

	old = *new;
	new->y = -old.z + (old.x + old.y) * sin(0.523599);
	new->x = (old.x - old.y) * cos(0.523599);
}

static void	ft_parallel_projection(t_pos *new)
{
	t_pos	old;

	old = *new;
	new->y = old.y - old.z * sin(0.785398);
	new->x = old.x - old.z * cos(0.785398);
}

t_pos	ft_transpos(t_pos p, int row, int col, const t_cam *cam)
{
	p.y *= cam->zoom;
	p.x *= cam->zoom;
	p.z *= cam->zoom / cam->depth;
	p.y -= (row * cam->zoom) / 2;
	p.x -= (col * cam->zoom) / 2;
	ft_rotate(&p, cam->alpha, cam->beta, cam->gamma);
	if (TYPE_ISOMETRIC == cam->type)
		ft_isometric_projection(&p);
	else
		ft_parallel_projection(&p);
	p.y += cam->height / 2 + cam->offset_y;
	p.x += cam->width / 2 + cam->offset_x;
	return (p);
}
