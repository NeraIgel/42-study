/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:15:47 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 11:39:05 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_fdf_bonus.h"

void	ft_fdf_init(t_fdf *f)
{
	f->mlx = NULL;
	f->win = NULL;
	ft_memset(&(f->img), 0, sizeof(t_img));
	ft_memset(&(f->cam), 0, sizeof(t_cam));
	ft_graphic_init(&(f->graphic));
}

void	ft_fdf_clear(t_fdf *f)
{
	if (f->mlx && f->img.img)
	{
		mlx_destroy_image(f->mlx, f->img.img);
		f->img.img = NULL;
	}
	if (f->mlx && f->win)
	{
		mlx_clear_window(f->mlx, f->win);
		mlx_destroy_window(f->mlx, f->win);
		f->win = NULL;
	}
	ft_graphic_clear(&(f->graphic));
}

void	ft_fdf_exit(t_fdf *f, const char *msg)
{
	if (msg)
		ft_putendl_fd((char *)msg, STDOUT_FILENO);
	ft_fdf_clear(f);
	exit(EXIT_SUCCESS);
}

void	ft_fdf_error(t_fdf *f, const char *errmsg)
{
	if (errmsg)
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	ft_fdf_clear(f);
	exit(EXIT_FAILURE);
}
