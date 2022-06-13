/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_setup_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:19:48 by heha              #+#    #+#             */
/*   Updated: 2022/06/12 19:01:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graphic.h"

static void	ft_grid_clear(t_pos ***grid, int row)
{
	int		y;
	t_pos	**cp;

	if (*grid)
	{
		y = 0;
		cp = *grid;
		while (y < row)
			free(cp[y++]);
		free(*grid);
		*grid = NULL;
	}
}

static t_pos	**ft_grid_create(int row, int col)
{
	t_pos	**grid;
	int		y;

	grid = (t_pos **)malloc(sizeof(t_pos *) * row);
	if (!grid)
		return (NULL);
	y = 0;
	while (y < row)
	{
		grid[y] = (t_pos *)malloc(sizeof(t_pos) * col);
		if (grid[y] == NULL)
		{
			ft_grid_clear(&grid, y);
			return (NULL);
		}
		y++;
	}
	return (grid);
}

static void	ft_grid_push_queue(t_pos **grid, int row, int col, t_queue *q)
{
	t_pos	*pos;
	int		y;
	int		x;

	y = 0;
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			if (!ft_queue_empty(q))
			{
				pos = ft_queue_front(q);
				ft_memcpy(&grid[y][x], pos, sizeof(t_pos));
				ft_queue_pop(q);
			}
			x++;
		}
		y++;
	}
}

bool	ft_graphic_save_data(t_graphic *g, int row, t_queue *q)
{
	t_pos	**grid;

	grid = ft_grid_create(row, g->col);
	if (!grid)
		return (ft_graphic_error(NULL, ERR_MALLOC));
	ft_grid_push_queue(grid, row, g->col, q);
	g->grid = grid;
	g->row = row;
	return (true);
}
