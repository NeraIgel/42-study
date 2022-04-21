/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_setup_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:57:41 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:42:50 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_elem.h"
#include "ft_checker_bonus.h"

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

static void	ft_checker_save_data(t_checker *c, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!ft_stack_push_argv(&(c->input), argv[i]))
			ft_checker_error(c, ERR_CHECKER);
		i++;
	}
}

static void	ft_checker_validate_data(t_checker *c)
{
	if (!ft_stack_check_dist(&(c->input)))
		ft_checker_error(c, ERR_CHECKER);
}

static void	ft_checker_tuning_data(t_checker *c)
{
	int			n;
	t_stack		tmp;
	t_element	elem;

	ft_stack_init(&tmp, ft_int_compare, ft_int_swap);
	ft_stack_copy(&tmp, &(c->input), sizeof(int));
	ft_stack_sort(&tmp);
	while (!ft_stack_empty(&(c->input)))
	{
		n = *(int *)ft_stack_top(&(c->input));
		elem = ft_stack_get_idx(&tmp, &n);
		ft_stack_push_back(&(c->a), &elem, sizeof(t_element));
		ft_stack_pop(&(c->input));
	}
	ft_stack_clear(&tmp);
}

void	ft_checker_setup(t_checker *c, int argc, char **argv)
{
	ft_checker_save_data(c, argc, argv);
	ft_checker_validate_data(c);
	ft_checker_tuning_data(c);
}
