/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:00:43 by heha              #+#    #+#             */
/*   Updated: 2022/09/21 16:15:35 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sphere.h"
#include "ft_utils.h"

static bool	ft_check_sphere_information(t_sphere *sp, char *const *tbl)
{
	static const int	clr_limit[2] = {0, 255};
	double				center[3];
	double				diameter;
	int					color[3];

	if (!ft_check_strtod_iter(*++tbl, NULL, center, 3))
		return (ft_sphere_error(NULL, "sphere format error (center)."));
	if (!ft_check_strtod_iter(*++tbl, NULL, &diameter, 1))
		return (ft_sphere_error(NULL, "sphere format error (diameter)."));
	if (!ft_check_strtoi_iter(*++tbl, clr_limit, color, 3))
		return (ft_sphere_error(NULL, "sphere format error (color)."));
	if (NULL != *++tbl)
		return (ft_sphere_error(NULL, "sphere format error (more info)"));
	sp->center = ft_point(center[0], center[1], center[2]);
	sp->diameter = diameter;
	sp->color = ft_color(color[0], color[1], color[2]);
	return (true);
}

bool	ft_sphere_setup(void **data, char *const *tbl)
{
	t_sphere	*sp;

	sp = ft_calloc(1U, sizeof(t_sphere));
	if (!sp)
		return (ft_sphere_error(sp, "Can't allocate memory."));
	if (!ft_check_sphere_information(sp, tbl))
		return (ft_sphere_error(sp, NULL));
	*data = sp;
	return (true);
}
