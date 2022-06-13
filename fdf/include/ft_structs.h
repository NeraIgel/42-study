/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:12:30 by heha              #+#    #+#             */
/*   Updated: 2022/06/12 19:00:15 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# include <stdbool.h>

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_pos
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_pos;

typedef struct s_line
{
	int		error;
	int		offset;
	int		sign_y;
	int		sign_x;
	int		delta_y;
	int		delta_x;
}	t_line;

typedef struct s_cam
{
	bool	invalidate;
	int		height;
	int		width;
	int		zoom;
	double	depth;
}	t_cam;

#endif
