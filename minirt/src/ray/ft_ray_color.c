/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:59:04 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 16:19:48 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_object.h"
#include "ft_ray.h"

t_color3	ft_ray_color(const t_ray *ray, t_scene *scene, t_deque *objects)
{
	t_hit_record	rec;

	ft_memset(&rec, 0, sizeof(t_hit_record));
	rec.t_min = EPSILON;
	rec.t_max = 10000.0;
	if (ft_objects_hit(objects, ray, &rec))
		return (ft_ray_phong_lighting(ray, scene, objects, &rec));
	else
		return (ft_color(0, 0, 0));
}
