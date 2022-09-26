/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:43:43 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 16:53:50 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_object.h"

bool	ft_is_object_type(const char *type)
{
	return (ft_is_sphere_type(type) \
			|| ft_is_plane_type(type) \
			|| ft_is_cylinder_type(type));
}

bool	ft_check_objects_initialized(const t_deque *objects)
{
	return (!ft_deque_empty(objects));
}

void	ft_objects_cleanup(t_deque *objects)
{
	t_object	*obj;

	while (!ft_deque_empty(objects))
	{
		obj = (t_object *)ft_deque_front(objects);
		free(obj->type);
		free(obj->data);
		ft_deque_pop(objects);
	}
}
