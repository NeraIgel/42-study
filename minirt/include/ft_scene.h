/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:07:25 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 16:52:32 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_H
# define FT_SCENE_H

# include "ft_camera.h"
# include "ft_lights.h"

typedef struct s_scene
{
	t_canvas	canvas;
	t_camera	camera;
	t_deque		lights;
	t_ambient	ambient;
}	t_scene;

bool	ft_is_scene_type(const char *type);
bool	ft_check_scene_initialized(const t_scene *scene);

bool	ft_scene_setup(t_scene *scene, char *const *tbl);
void	ft_set_scene_info(t_scene *scene);

#endif
