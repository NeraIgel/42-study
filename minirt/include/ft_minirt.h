/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:45:14 by heha              #+#    #+#             */
/*   Updated: 2022/09/22 18:07:18 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINIRT_H
# define FT_MINIRT_H

# include "ft_graphic.h"

typedef struct s_minirt
{
	void		*mlx;
	t_win		win;
	t_img		img;
	t_hook		hook;
	t_graphic	graphic;
}	t_minirt;

void	ft_minirt_create_window(t_minirt *rt, const char *scenefile);
void	ft_minirt_message_loop(t_minirt *rt);
void	ft_minirt_hook(t_minirt *rt, int keycode);

void	ft_minirt_error(t_minirt *rt, const char *errmsg);
void	ft_minirt_exit(t_minirt *rt);

void	ft_minirt_hook_camera(t_camera *cam, int keycode, t_minirt *rt);
void	ft_minirt_hook_light(t_light *light, int keycode, t_minirt *rt);
void	ft_minirt_hook_sp(t_object *sphere, int keycode, t_minirt *rt);
void	ft_minirt_hook_pl(t_object *plane, int keycode, t_minirt *rt);
void	ft_minirt_hook_cy(t_object *cylinder, int keycode, t_minirt *rt);

void	*ft_find_light(t_deque *lights, size_t l_i);
void	*ft_check_type(t_deque *objs, const char *type, size_t n, size_t h_i);
void	ft_minirt_hook_indexing(size_t *index, size_t *size);
void	ft_color_range_check(t_color3 *color);
void	ft_normalized_vec_range_check(t_vec3 *normal);
void	ft_minirt_hook_color(t_color3 *color, int keycode, t_minirt *rt);
void	ft_minirt_hook_albedo(t_color3 *color, int keycode, t_minirt *rt);
void	ft_minirt_hook_point(t_point3 *point, int keycode, t_minirt *rt);

#endif
