/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:41:04 by heha              #+#    #+#             */
/*   Updated: 2022/09/23 13:01:22 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;

t_vec3		ft_vec(double x, double y, double z);
t_point3	ft_point(double x, double y, double z);
t_color3	ft_color(double r, double g, double b);
int			ft_trgb(int t, int r, int g, int b);
double		ft_vec_length(t_vec3 vec);
double		ft_vec_length_squared(t_vec3 vec);
t_vec3		ft_vec_add(t_vec3 vec1, t_vec3 vec2);
t_vec3		ft_vec_sub(t_vec3 vec1, t_vec3 vec2);
t_vec3		ft_vec_mul(t_vec3 vec1, t_vec3 vec2);
t_vec3		ft_vec_mul_t(t_vec3 vec, double t);
t_vec3		ft_vec_div_t(t_vec3 vec, double t);
t_vec3		ft_vec_unit(t_vec3 vec);
double		ft_vec_dot(t_vec3 vec1, t_vec3 vec2);
t_vec3		ft_vec_cross(t_vec3 vec1, t_vec3 vec2);
t_vec3		ft_vec_min(t_vec3 vec1, t_vec3 vec2);

#endif
