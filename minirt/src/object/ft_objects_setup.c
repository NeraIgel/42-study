/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:31 by heha              #+#    #+#             */
/*   Updated: 2022/09/22 17:39:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_object.h"

static bool	ft_sphere(t_object *obj, size_t *obj_size, char *const *tbl)
{
	if (!ft_sphere_setup(&(obj->data), tbl))
		return (false);
	*obj_size = sizeof(t_sphere);
	obj->type = ft_strdup("sp");
	obj->vtable.ft_hit = ft_sphere_hit;
	return (true);
}

static bool	ft_plane(t_object *obj, size_t *obj_size, char *const *tbl)
{
	if (!ft_plane_setup(&(obj->data), tbl))
		return (false);
	*obj_size = sizeof(t_plane);
	obj->type = ft_strdup("pl");
	obj->vtable.ft_hit = ft_plane_hit;
	return (true);
}

static bool	ft_cylinder(t_object *obj, size_t *obj_size, char *const *tbl)
{
	if (!ft_cylinder_setup(&(obj->data), tbl))
		return (false);
	*obj_size = sizeof(t_cylinder);
	obj->type = ft_strdup("cy");
	obj->vtable.ft_hit = ft_cylinder_hit;
	return (true);
}

bool	ft_objects_setup(t_deque *objects, char *const *tbl)
{
	t_object	obj;
	size_t		obj_size;

	ft_memset(&obj, 0, sizeof(t_object));
	if (ft_is_sphere_type(tbl[0]) && !ft_sphere(&obj, &obj_size, tbl))
		return (false);
	else if (ft_is_plane_type(tbl[0]) && !ft_plane(&obj, &obj_size, tbl))
		return (false);
	else if (ft_is_cylinder_type(tbl[0]) && !ft_cylinder(&obj, &obj_size, tbl))
		return (false);
	ft_deque_push(objects, &obj, obj_size);
	return (true);
}
