/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:51:35 by heha              #+#    #+#             */
/*   Updated: 2022/09/23 17:41:34 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cylinder.h"
#include "ft_utils.h"

static bool	ft_check_cylinder_information1(t_cylinder *cy, char *const *tbl)
{
	static const double	nor_limit[2] = {-1.0, 1.0};
	double				point[3];
	double				normal[3];
	double				diameter;
	double				height;

	if (!ft_check_strtod_iter(*++tbl, NULL, point, 3))
		return (ft_cylinder_error(NULL, "cylinder format error (point)."));
	if (!ft_check_strtod_iter(*++tbl, nor_limit, normal, 3))
		return (ft_cylinder_error(NULL, "cylinder format error (normal)."));
	if (!ft_check_strtod_iter(*++tbl, NULL, &diameter, 1))
		return (ft_cylinder_error(NULL, "cylinder format error (diameter)."));
	if (!ft_check_strtod_iter(*++tbl, NULL, &height, 1))
		return (ft_cylinder_error(NULL, "cylinder format error (height)."));
	cy->point = ft_point(point[0], point[1], point[2]);
	cy->normal = ft_vec_unit(ft_vec(normal[0], normal[1], normal[2]));
	cy->diameter = diameter;
	cy->height = height;
	return (true);
}

static bool	ft_check_cylinder_information2(t_cylinder *cy, char *const *tbl)
{
	static const int	clr_limit[2] = {0, 255};
	int					color[3];

	if (!ft_check_strtoi_iter(*++tbl, clr_limit, color, 3))
		return (ft_cylinder_error(NULL, "cylinder format error (color)."));
	if (NULL != *++tbl)
		return (ft_cylinder_error(NULL, "cylinder format error (more info)"));
	cy->color = ft_color(color[0], color[1], color[2]);
	return (true);
}

bool	ft_cylinder_setup(void **data, char *const *tbl)
{
	t_cylinder	*cy;

	cy = ft_calloc(1U, sizeof(t_cylinder));
	if (!cy)
		return (ft_cylinder_error(cy, "Can't allocate memory."));
	if (!ft_check_cylinder_information1(cy, tbl))
		return (ft_cylinder_error(cy, NULL));
	if (!ft_check_cylinder_information2(cy, tbl + 4))
		return (ft_cylinder_error(cy, NULL));
	*data = cy;
	return (true);
}
