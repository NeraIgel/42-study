/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:41:29 by heha              #+#    #+#             */
/*   Updated: 2022/09/23 17:42:16 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_camera.h"
#include "ft_utils.h"

static bool	ft_check_camera_information(t_camera *cam, char *const *tbl)
{
	static const double	dir_limit[2] = {-1.0, 1.0};
	static const int	fov_limit[2] = {0, FOV_LIMIT};
	double				orig[3];
	double				dir[3];
	int					fov;

	if (cam->initialized)
		return (ft_camera_error("camera duplicate creation error."));
	if (!ft_check_strtod_iter(*++tbl, NULL, orig, 3))
		return (ft_camera_error("camera format error (orig)."));
	if (!ft_check_strtod_iter(*++tbl, dir_limit, dir, 3))
		return (ft_camera_error("camera format error (dir)."));
	if (!ft_check_strtoi_iter(*++tbl, fov_limit, &fov, 1))
		return (ft_camera_error("camera format error (fov)."));
	if (NULL != *++tbl)
		return (ft_camera_error("camera format error (more info)"));
	cam->orig = ft_point(orig[0], orig[1], orig[2]);
	cam->dir = ft_vec_unit(ft_vec(dir[0], dir[1], dir[2]));
	cam->fov = fov;
	cam->initialized = true;
	return (true);
}

static void	ft_canvas(t_canvas *cav, int width, int height)
{
	cav->width = width;
	cav->height = height;
	cav->aspect_ratio = (double)width / height;
}

bool	ft_camera_setup(t_camera *cam, t_canvas *cav, char *const *tbl)
{
	if (!ft_check_camera_information(cam, tbl))
		return (ft_camera_error(NULL));
	ft_canvas(cav, 1200, 900);
	return (true);
}
