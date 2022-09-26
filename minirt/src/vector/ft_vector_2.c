/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:58:10 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 12:58:55 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec3	ft_vec_add(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	out;

	out.x = vec1.x + vec2.x;
	out.y = vec1.y + vec2.y;
	out.z = vec1.z + vec2.z;
	return (out);
}

t_vec3	ft_vec_sub(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	out;

	out.x = vec1.x - vec2.x;
	out.y = vec1.y - vec2.y;
	out.z = vec1.z - vec2.z;
	return (out);
}

t_vec3	ft_vec_mul(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	out;

	out.x = vec1.x * vec2.x;
	out.y = vec1.y * vec2.y;
	out.z = vec1.z * vec2.z;
	return (out);
}

t_vec3	ft_vec_mul_t(t_vec3 vec, double t)
{
	t_vec3	out;

	out.x = vec.x * t;
	out.y = vec.y * t;
	out.z = vec.z * t;
	return (out);
}

t_vec3	ft_vec_div_t(t_vec3 vec, double t)
{
	t_vec3	out;

	out.x = vec.x * (1 / t);
	out.y = vec.y * (1 / t);
	out.z = vec.z * (1 / t);
	return (out);
}
