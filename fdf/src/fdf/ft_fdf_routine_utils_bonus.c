/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_routine_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:49:49 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 11:39:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key_macos.h"
#include "ft_enums_bonus.h"
#include "ft_structs_bonus.h"

void	ft_hook_type(t_cam *cam, int keycode)
{
	int		type;

	if (K_NP_1 == keycode)
		type = TYPE_ISOMETRIC;
	else
		type = TYPE_PARALLEL;
	if (type != cam->type)
	{
		cam->invalidate = true;
		cam->type = type;
	}
}

void	ft_hook_zoom(t_cam *cam, int keycode)
{
	int		zoom;

	zoom = cam->zoom;
	if (K_NP_MIN == keycode)
		zoom--;
	else
		zoom++;
	if (zoom > 0)
	{
		cam->invalidate = true;
		cam->zoom = zoom;
	}
}

void	ft_hook_depth(t_cam *cam, int keycode)
{
	double	depth;

	depth = cam->depth;
	if (K_PG_U == keycode)
		depth -= 0.4;
	else
		depth += 0.4;
	if (depth > MIN_DEPTH && depth < MAX_DEPTH)
	{
		cam->invalidate = true;
		cam->depth = depth;
	}
}

void	ft_hook_offset(t_cam *cam, int keycode)
{
	cam->invalidate = true;
	if (K_AR_U == keycode)
		cam->offset_y -= OFFSET;
	else if (K_AR_D == keycode)
		cam->offset_y += OFFSET;
	else if (K_AR_L == keycode)
		cam->offset_x -= OFFSET;
	else
		cam->offset_x += OFFSET;
}

void	ft_hook_rotate(t_cam *cam, int keycode)
{
	cam->invalidate = true;
	if (K_X == keycode)
		cam->alpha += 0.05;
	else if (K_W == keycode)
		cam->alpha -= 0.05;
	else if (K_A == keycode)
		cam->beta -= 0.05;
	else if (K_D == keycode)
		cam->beta += 0.05;
	else if (K_Q == keycode)
		cam->gamma -= 0.05;
	else
		cam->gamma += 0.05;
}
