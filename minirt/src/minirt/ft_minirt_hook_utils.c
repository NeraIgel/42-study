/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt_hook_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:12:47 by chpark            #+#    #+#             */
/*   Updated: 2022/09/22 18:32:29 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_key_mac.h"
#include "ft_minirt.h"

void	*ft_find_light(t_deque *lights, size_t l_i)
{
	size_t	i;
	t_light	*light;

	i = -1;
	while (++i <= l_i)
		light = ft_deque_at(lights, i);
	return (light);
}

void	*ft_check_type(t_deque *objs, const char *type, size_t n, size_t h_i)
{
	size_t		i;
	size_t		j;
	t_object	*obj;

	i = 0;
	j = -1;
	while (i <= h_i)
	{
		while (++j <= n - 1)
		{
			obj = ft_deque_at(objs, j);
			if (!ft_strcmp(obj->type, type))
				break ;
		}
		i++;
	}
	return (obj);
}

void	ft_minirt_hook_indexing(size_t *index, size_t *size)
{
	if (*index >= *size - 1)
		*index = 0;
	else
		*index += 1;
}

void	ft_color_range_check(t_color3 *color)
{
	if (color->x >= 255)
		color->x = 255;
	if (color->x <= 0)
		color->x = 0;
	if (color->y >= 255)
		color->y = 255;
	if (color->y <= 0)
		color->y = 0;
	if (color->z >= 255)
		color->z = 255;
	if (color->z <= 0)
		color->z = 0;
}

void	ft_normalized_vec_range_check(t_vec3 *normal)
{
	if (normal->x >= 1)
		normal->x = 1;
	if (normal->x <= -1)
		normal->x = -1;
	if (normal->y >= 1)
		normal->y = 1;
	if (normal->y <= -1)
		normal->y = -1;
	if (normal->z >= 1)
		normal->z = 1;
	if (normal->z <= -1)
		normal->z = -1;
}
