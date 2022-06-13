/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:14:09 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 11:39:58 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_BONUS_H
# define FT_STRUCTS_BONUS_H

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
	int		type;
	int		offset_y;
	int		offset_x;
	double	alpha;
	double	beta;
	double	gamma;
}	t_cam;

#endif
