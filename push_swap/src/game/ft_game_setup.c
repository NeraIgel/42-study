/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:51:37 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:43:28 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_elem.h"
#include "ft_game.h"

static bool	ft_stack_push_argv(t_stack *s, const char *str)
{
	int		n;
	char	*endptr;

	while (1)
	{
		n = ft_strtoi(str, &endptr);
		if (str == endptr)
			return (false);
		ft_stack_push_back(s, &n, sizeof(int));
		str = endptr;
		while (*str && ft_isspace(*str))
			str++;
		if (*str == '\0')
			break ;
	}
	return (true);
}

static void	ft_game_save_data(t_game *g, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!ft_stack_push_argv(&(g->input), argv[i]))
			ft_game_error(g, ERR_GAME);
		i++;
	}
}

static void	ft_game_validate_data(t_game *g)
{
	if (!ft_stack_check_dist(&(g->input)))
		ft_game_error(g, ERR_GAME);
}

static void	ft_game_tuning_data(t_game *g)
{
	int			n;
	t_stack		tmp;
	t_element	elem;

	ft_stack_init(&tmp, ft_int_compare, ft_int_swap);
	ft_stack_copy(&tmp, &(g->input), sizeof(int));
	ft_stack_sort(&tmp);
	while (!ft_stack_empty(&(g->input)))
	{
		n = *(int *)ft_stack_top(&(g->input));
		elem = ft_stack_get_idx(&tmp, &n);
		ft_stack_push_back(&(g->a), &elem, sizeof(t_element));
		ft_stack_pop(&(g->input));
	}
	ft_stack_clear(&tmp);
}

void	ft_game_setup(t_game *g, int argc, char **argv)
{
	ft_game_save_data(g, argc, argv);
	ft_game_validate_data(g);
	ft_game_tuning_data(g);
}
