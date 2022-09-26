/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:31:11 by heha              #+#    #+#             */
/*   Updated: 2022/09/21 21:32:33 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLANE_H
# define FT_PLANE_H

# include "ft_ray.h"

typedef struct s_plane
{
	t_color3	color;
	t_point3	point;
	t_vec3		normal;
	t_color3	albedo;
}	t_plane;

bool	ft_is_plane_type(const char *type);
bool	ft_plane_error(t_plane *pl, const char *errmsg);

bool	ft_plane_setup(void **data, char *const *tbl);

int		ft_plane_hit(const void *data, const t_ray *ray, t_hit_record *rec);

#endif
