/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:35:06 by heha              #+#    #+#             */
/*   Updated: 2022/09/23 17:41:20 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_plane.h"
#include "ft_utils.h"

static bool	ft_check_plane_information(t_plane *pl, char *const *tbl)
{
	static const double	nor_limit[2] = {-1.0, 1.0};
	static const int	clr_limit[2] = {0, 255};
	double				point[3];
	double				normal[3];
	int					color[3];

	if (!ft_check_strtod_iter(*++tbl, NULL, point, 3))
		return (ft_plane_error(NULL, "plane format error (point)."));
	if (!ft_check_strtod_iter(*++tbl, nor_limit, normal, 3))
		return (ft_plane_error(NULL, "plane format error (normal)."));
	if (!ft_check_strtoi_iter(*++tbl, clr_limit, color, 3))
		return (ft_plane_error(NULL, "plane format error (color)."));
	if (NULL != *++tbl)
		return (ft_plane_error(NULL, "plane format error (more info)"));
	pl->point = ft_point(point[0], point[1], point[2]);
	pl->normal = ft_vec_unit(ft_vec(normal[0], normal[1], normal[2]));
	pl->color = ft_color(color[0], color[1], color[2]);
	return (true);
}

bool	ft_plane_setup(void **data, char *const *tbl)
{
	t_plane	*pl;

	pl = ft_calloc(1U, sizeof(t_plane));
	if (!pl)
		return (ft_plane_error(pl, "Can't allocate memory."));
	if (!ft_check_plane_information(pl, tbl))
		return (ft_plane_error(pl, NULL));
	*data = pl;
	return (true);
}
