/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:57:30 by heha              #+#    #+#             */
/*   Updated: 2022/09/21 21:32:27 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPHERE_H
# define FT_SPHERE_H

# include "ft_ray.h"

typedef struct s_sphere
{
	t_color3	color;
	t_point3	center;
	double		diameter;
	double		radius;
	t_color3	albedo;
}	t_sphere;

bool	ft_is_sphere_type(const char *type);
bool	ft_sphere_error(t_sphere *sp, const char *errmsg);

bool	ft_sphere_setup(void **data, char *const *tbl);

int		ft_sphere_hit(const void *data, const t_ray *ray, t_hit_record *rec);

#endif
