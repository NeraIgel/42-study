/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_draw_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:21:54 by heha              #+#    #+#             */
/*   Updated: 2022/06/12 19:01:34 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_structs.h"

static void	ft_isometric_projection(t_pos *new)
{
	t_pos	old;

	old = *new;
	new->y = -old.z + (old.x + old.y) * sin(0.523599);
	new->x = (old.x - old.y) * cos(0.523599);
}

t_pos	ft_transpos(t_pos p, int row, int col, const t_cam *cam)
{
	p.y *= cam->zoom;
	p.x *= cam->zoom;
	p.z *= cam->zoom / cam->depth;
	p.y -= (row * cam->zoom) / 2;
	p.x -= (col * cam->zoom) / 2;
	ft_isometric_projection(&p);
	p.y += cam->height / 2;
	p.x += cam->width / 2;
	return (p);
}
