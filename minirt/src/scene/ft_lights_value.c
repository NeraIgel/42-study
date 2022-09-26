/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lights_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:54:13 by heha              #+#    #+#             */
/*   Updated: 2022/09/22 16:44:39 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lights.h"

void	ft_set_lights_value(t_deque *lights)
{
	size_t	i;
	t_light	*light;

	i = 0U;
	while (i < ft_deque_size(lights))
	{
		light = (t_light *)ft_deque_at(lights, i);
		light->value = ft_vec_div_t(light->color, 255.0);
		i++;
	}
}

void	ft_set_ambient_value(t_ambient *ambient)
{
	ambient->value = ft_vec_div_t(ambient->color, 255.0);
	ambient->value = ft_vec_mul_t(ambient->value, ambient->ratio);
}
