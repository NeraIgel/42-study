/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:59:02 by heha              #+#    #+#             */
/*   Updated: 2022/09/23 16:56:27 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

static void	ft_error(const char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd("\033[31;1mError\033[0m", STDERR_FILENO);
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}

t_vec3	ft_vec_unit(t_vec3 vec)
{
	double	len;

	len = ft_vec_length(vec);
	if (0.0 == len)
		ft_error("Devider is 0.");
	return (ft_vec_div_t(vec, len));
}

double	ft_vec_dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vec3	ft_vec_cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	out;

	out.x = vec1.y * vec2.z - vec1.z * vec2.y;
	out.y = vec1.z * vec2.x - vec1.x * vec2.z;
	out.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (out);
}

t_vec3	ft_vec_min(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	out;

	out = vec1;
	if (vec1.x > vec2.x)
		out.x = vec2.x;
	if (vec1.y > vec2.y)
		out.y = vec2.y;
	if (vec1.z > vec2.z)
		out.z = vec2.z;
	return (out);
}
