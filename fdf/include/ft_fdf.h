/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:06:01 by heha              #+#    #+#             */
/*   Updated: 2022/06/12 18:57:47 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "ft_graphic.h"

# define MSG_QUIT			"\033[32;1mSuccessfully terminated:\033[0m by quit"
# define MSG_ESC			"\033[32;1mSuccessfully terminated:\033[0m by esc"

# define ERR_MAP_SIZE		"\033[31;1mError:\033[0m Map size is too large."
# define ERR_MLX_INIT		"\033[31;1mError:\033[0m Can't init mlx."
# define ERR_MLX_WINSURF	"\033[31;1mError:\033[0m Can't get window surface."
# define ERR_MLX_IMGSURF	"\033[31;1mError:\033[0m Can't get image surface."
# define ERR_MLX_IMGDATA	"\033[31;1mError:\033[0m Can't get image data."

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_cam		cam;
	t_graphic	graphic;
}	t_fdf;

void	ft_fdf_init(t_fdf *f);
void	ft_fdf_clear(t_fdf *f);
void	ft_fdf_exit(t_fdf *f, const char *msg);
void	ft_fdf_error(t_fdf *f, const char *errmsg);
void	ft_fdf_setup(t_fdf *f, char *argv[]);
void	ft_fdf_routine(t_fdf *f);

int		ft_set_windowsize(int *height, int *width, int row, int col);
double	ft_set_depth(int row, int col);

#endif
