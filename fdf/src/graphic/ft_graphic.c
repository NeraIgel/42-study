/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:36:57 by heha              #+#    #+#             */
/*   Updated: 2022/06/12 19:00:53 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphic.h"

void	ft_graphic_init(t_graphic *g)
{
	g->grid = NULL;
	g->row = 0;
	g->col = 0;
}

void	ft_graphic_clear(t_graphic *g)
{
	int		y;

	if (g->grid)
	{
		y = 0;
		while (y < g->row)
			free(g->grid[y++]);
		free(g->grid);
		g->grid = NULL;
	}
	g->row = 0;
	g->col = 0;
}

bool	ft_graphic_error(t_graphic *g, const char *errmsg)
{
	if (errmsg)
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	if (g)
		ft_graphic_clear(g);
	return (false);
}
