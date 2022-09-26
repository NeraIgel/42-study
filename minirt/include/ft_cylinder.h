/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:46:58 by heha              #+#    #+#             */
/*   Updated: 2022/09/23 13:05:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CYLINDER_H
# define FT_CYLINDER_H

# include "ft_ray.h"

# define CYL_CAP_TOP	0
# define CYL_CAP_BOT	1

typedef struct s_cylinder
{
	t_color3	color;
	t_point3	point;
	t_vec3		normal;
	double		height;
	double		diameter;
	double		radius;
	t_color3	albedo;
	t_point3	cap_top;
	t_point3	cap_bot;
}	t_cylinder;

bool	ft_is_cylinder_type(const char *type);
bool	ft_cylinder_error(t_cylinder *cy, const char *errmsg);

bool	ft_cylinder_setup(void **data, char *const *tbl);

int		ft_cylinder_hit(const void *data, const t_ray *ray, t_hit_record *rec);
bool	hit_cylinder_cap(\
		const t_cylinder *cy, const t_ray *ray, t_hit_record *rec, int mode);

#endif
