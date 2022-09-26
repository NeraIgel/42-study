/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lights.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:24:52 by heha              #+#    #+#             */
/*   Updated: 2022/09/22 12:51:02 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIGHTS_H
# define FT_LIGHTS_H

# include "ft_deque.h"
# include "ft_vector.h"

typedef struct s_light
{
	t_point3	orig;
	t_color3	color;
	double		ratio;
	t_color3	value;
}	t_light;

typedef struct s_ambient
{
	t_color3	color;
	double		ratio;
	bool		initialized;
	t_color3	value;
}	t_ambient;

bool	ft_is_light_type(const char *type);
bool	ft_is_ambient_type(const char *type);
bool	ft_lights_error(const char *errmsg);

bool	ft_lights_setup(t_deque *lights, char *const *tbl);
bool	ft_ambient_setup(t_ambient *ambient, char *const *tbl);
void	ft_set_lights_value(t_deque *lights);
void	ft_set_ambient_value(t_ambient *ambient);

#endif
