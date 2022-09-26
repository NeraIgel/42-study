/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:53:22 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 20:53:32 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHIC_H
# define FT_GRAPHIC_H

# include "ft_scene.h"
# include "ft_object.h"
# include "ft_structs.h"

typedef struct s_graphic
{
	t_scene	scene;
	t_deque	objects;
}	t_graphic;

void	ft_graphic_init(t_graphic *g);
void	ft_graphic_destroy(t_graphic *g);
bool	ft_graphic_error(t_graphic *g, const char *errmsg);
bool	ft_graphic_setup(t_graphic *g, const char *scenefile);
void	ft_graphic_render(t_graphic *g, t_img *img);

#endif
