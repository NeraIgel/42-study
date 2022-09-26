/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lights_setup_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:44:52 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 18:49:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lights.h"
#include "ft_utils.h"

static bool	ft_check_light_information(t_light *light, char *const *tbl)
{
	static const double	ratio_limit[2] = {0.0, 1.0};
	static const int	color_limit[2] = {0, 255};
	double				orig[3];
	double				ratio;
	int					color[3];

	if (!ft_check_strtod_iter(*++tbl, NULL, orig, 3))
		return (ft_lights_error("light format error (orig)."));
	if (!ft_check_strtod_iter(*++tbl, ratio_limit, &ratio, 1))
		return (ft_lights_error("light format error (ratio)."));
	if (!ft_check_strtoi_iter(*++tbl, color_limit, color, 3))
		return (ft_lights_error("light format error (color)."));
	if (NULL != *++tbl)
		return (ft_lights_error("light format error (more info)"));
	light->orig = ft_point(orig[0], orig[1], orig[2]);
	light->ratio = ratio;
	light->color = ft_color(color[0], color[1], color[2]);
	return (true);
}

bool	ft_lights_setup(t_deque *lights, char *const *tbl)
{
	t_light	light;

	ft_memset(&light, 0, sizeof(t_light));
	if (!ft_check_light_information(&light, tbl))
		return (false);
	ft_deque_push(lights, &light, sizeof(t_light));
	return (true);
}

bool	ft_ambient_setup(t_ambient *ambient, char *const *tbl)
{
	static const double	ratio_limit[2] = {0.0, 1.0};
	static const int	color_limit[2] = {0, 255};
	double				ratio;
	int					color[3];

	if (ambient->initialized)
		return (ft_lights_error("ambient duplicate creation error."));
	if (!ft_check_strtod_iter(*++tbl, ratio_limit, &ratio, 1))
		return (ft_lights_error("ambient format error (ratio)."));
	if (!ft_check_strtoi_iter(*++tbl, color_limit, color, 3))
		return (ft_lights_error("ambient format error (color)."));
	if (NULL != *++tbl)
		return (ft_lights_error("ambient format error (more info)"));
	ambient->ratio = ratio;
	ambient->color = ft_color(color[0], color[1], color[2]);
	ambient->initialized = true;
	return (true);
}
