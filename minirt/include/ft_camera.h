/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:24:35 by heha              #+#    #+#             */
/*   Updated: 2022/09/21 21:32:58 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAMERA_H
# define FT_CAMERA_H

# include <stdbool.h>
# include "ft_vector.h"

# define FOV_LIMIT	180

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_camera
{
	t_point3	orig;
	t_vec3		dir;
	int			fov;
	bool		initialized;
	t_vec3		vertical;
	t_vec3		horizontal;
	double		focal_length;
	double		viewport_width;
	double		viewport_height;
	t_point3	lower_left_corner;
}	t_camera;

bool	ft_is_camera_type(const char *type);
bool	ft_camera_error(const char *errmsg);

bool	ft_camera_setup(t_camera *camera, t_canvas *canvas, char *const *tbl);
void	ft_set_camera_viewport(t_camera *camera, const t_canvas *canvas);

#endif
