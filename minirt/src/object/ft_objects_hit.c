/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objects_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:51:31 by heha              #+#    #+#             */
/*   Updated: 2022/09/21 15:51:43 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_object.h"

bool	ft_objects_hit(t_deque *objects, const t_ray *ray, t_hit_record *rec)
{
	size_t			i;
	t_object		*obj;
	t_hit_record	temp_rec;
	bool			hit_anything;

	i = 0U;
	temp_rec = *rec;
	hit_anything = false;
	while (i < ft_deque_size(objects))
	{
		obj = (t_object *)ft_deque_at(objects, i);
		if (obj->vtable.ft_hit(obj->data, ray, &temp_rec))
		{
			hit_anything = true;
			temp_rec.t_max = temp_rec.t;
			*rec = temp_rec;
		}
		i++;
	}
	return (hit_anything);
}
