/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:56:59 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:42:36 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_elem.h"
#include "ft_checker_bonus.h"

void	ft_checker_init(t_checker *c)
{
	ft_stack_init(&(c->a), ft_elem_compare, NULL);
	ft_stack_init(&(c->b), ft_elem_compare, NULL);
	ft_stack_init(&(c->input), ft_int_compare, NULL);
}

void	ft_checker_clear(t_checker *c)
{
	ft_stack_clear(&(c->a));
	ft_stack_clear(&(c->b));
	ft_stack_clear(&(c->input));
}

void	ft_checker_error(t_checker *c, char *errmsg)
{
	if (errmsg)
		ft_putendl_fd(errmsg, STDERR_FILENO);
	ft_checker_clear(c);
	exit(EXIT_FAILURE);
}
