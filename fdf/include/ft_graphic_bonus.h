/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:13:30 by heha              #+#    #+#             */
/*   Updated: 2022/06/13 11:40:05 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPHIC_BONUS_H
# define FT_GRAPHIC_BONUS_H

# include "ft_queue.h"
# include "ft_structs_bonus.h"

# define ERR_MALLOC		"\033[31;1mError:\033[0m Can't allocate memory."
# define ERR_FILE_NAME	"\033[31;1mError:\033[0m Wrong filename."
# define ERR_FILE_OPEN	"\033[31;1mError:\033[0m Can't file open."
# define ERR_FILE_READ	"\033[31;1mError:\033[0m Can't file read."
# define ERR_FILE_EMPTY	"\033[31;1mError:\033[0m Empty file."
# define ERR_ROW_EMPTY	"\033[31;1mError:\033[0m Empty row within the file."
# define ERR_MAP_WIDTH	"\033[31;1mError:\033[0m Map width isn't same all rows."
# define ERR_MAP_FORMAT	"\033[31;1mError:\033[0m Incorrect row format."

typedef struct s_graphic
{
	t_pos	**grid;
	int		row;
	int		col;
}	t_graphic;

void	ft_graphic_init(t_graphic *g);
void	ft_graphic_clear(t_graphic *g);
bool	ft_graphic_error(t_graphic *g, const char *errmsg);
bool	ft_graphic_setup(t_graphic *g, const char *file);
bool	ft_graphic_save_data(t_graphic *g, int row, t_queue *q);
void	ft_graphic_draw(const t_graphic *g, const t_cam *cam, t_img *img);

t_pos	ft_transpos(t_pos p, int row, int col, const t_cam *cam);

#endif
