/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_setup_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:16:45 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 11:39:13 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_enums_bonus.h"

int	ft_set_windowsize(int *height, int *width, int row, int col)
{
	int		zoom;

	zoom = DEF_ZOOM;
	while (zoom >= 1)
	{
		*height = 0;
		*width = 0;
		while (*height <= WIN_MAX_HEIGHT && *height < row * zoom \
				&& *width <= WIN_MAX_WIDTH && *width < col * zoom)
		{
			*height += HEIGHT_MARGIN;
			*width += WIDTH_MARGIN;
		}
		if (*height < WIN_MAX_HEIGHT && *width < WIN_MAX_WIDTH)
			break ;
		zoom--;
	}
	while (*height < row * zoom + HEIGHT_MARGIN \
			|| *width < col * zoom + WIDTH_MARGIN)
	{
		*height += HEIGHT_MARGIN;
		*width += WIDTH_MARGIN;
	}
	return (zoom);
}

double	ft_set_depth(int row, int col)
{
	double	depth;

	depth = fabs((double)row - col);
	if (depth < MIN_DEPTH)
		return (MIN_DEPTH);
	else if (depth > MAX_DEPTH)
		return (MAX_DEPTH);
	else
		return (depth);
}
