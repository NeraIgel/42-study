/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:43:18 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 16:53:41 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OBJECT_H
# define FT_OBJECT_H

# include "ft_sphere.h"
# include "ft_plane.h"
# include "ft_cylinder.h"

struct s_object_vtable
{
	int	(*ft_hit)(const void *data, const t_ray *ray, t_hit_record *rec);
};

typedef struct s_object
{
	char					*type;
	void					*data;
	struct s_object_vtable	vtable;
}	t_object;

bool	ft_is_object_type(const char *type);
bool	ft_check_objects_initialized(const t_deque *objects);
void	ft_objects_cleanup(t_deque *objects);

bool	ft_objects_setup(t_deque *objects, char *const *tbl);

bool	ft_objects_hit(t_deque *objects, const t_ray *ray, t_hit_record *rec);

#endif
