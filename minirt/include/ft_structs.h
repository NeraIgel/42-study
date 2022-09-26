/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:13:14 by heha              #+#    #+#             */
/*   Updated: 2022/09/22 18:15:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_win
{
	void	*win;
	int		width;
	int		height;
	char	*title;
	bool	invalidate;
}	t_win;

typedef struct s_hook
{
	size_t	mode;
	size_t	sp_size;
	size_t	pl_size;
	size_t	cy_size;
	size_t	sp_index;
	size_t	pl_index;
	size_t	cy_index;
	size_t	lights_size;
	size_t	lights_index;
}	t_hook;

#endif
