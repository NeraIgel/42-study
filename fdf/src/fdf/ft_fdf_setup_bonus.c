/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_setup_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:16:10 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 11:39:10 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_fdf_bonus.h"
#include "ft_enums_bonus.h"

static void	ft_fdf_graphic_data_save(t_fdf *f, char *argv[])
{
	if (!ft_graphic_setup(&(f->graphic), argv[1]))
		ft_fdf_error(f, NULL);
	if (f->graphic.row >= WIN_MAX_HEIGHT || f->graphic.col >= WIN_MAX_WIDTH)
		ft_fdf_error(f, ERR_MAP_SIZE);
}

static void	ft_fdf_cam_data_save(t_fdf *f)
{
	const int	row = f->graphic.row;
	const int	col = f->graphic.col;

	f->cam.invalidate = true;
	f->cam.zoom = ft_set_windowsize(&f->cam.height, &f->cam.width, row, col);
	f->cam.depth = ft_set_depth(row, col);
	f->cam.type = TYPE_ISOMETRIC;
}

static void	ft_fdf_mlx_data_save(t_fdf *f)
{
	f->mlx = mlx_init();
	if (!(f->mlx))
		ft_fdf_error(f, ERR_MLX_INIT);
	f->win = mlx_new_window(f->mlx, f->cam.width, f->cam.height, WIN_TITLE);
	if (!(f->win))
		ft_fdf_error(f, ERR_MLX_WINSURF);
	f->img.img = mlx_new_image(f->mlx, f->cam.width, f->cam.height);
	if (!(f->img.img))
		ft_fdf_error(f, ERR_MLX_IMGSURF);
	f->img.data = mlx_get_data_addr(f->img.img, \
			&f->img.bits_per_pixel, &f->img.line_length, &f->img.endian);
	if (!(f->img.data))
		ft_fdf_error(f, ERR_MLX_IMGDATA);
}

void	ft_fdf_setup(t_fdf *f, char *argv[])
{
	ft_fdf_graphic_data_save(f, argv);
	ft_fdf_cam_data_save(f);
	ft_fdf_mlx_data_save(f);
}
