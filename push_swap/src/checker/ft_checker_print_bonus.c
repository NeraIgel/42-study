/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_print_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:57:18 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:42:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_elem.h"
#include "ft_checker_bonus.h"

static void	ft_elem_print(void *content)
{
	ft_putnbr_fd(*(t_element *)content, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
}

static void	ft_stack_print(t_stack *s, char *name)
{
	ft_putstr_fd(name, STDOUT_FILENO);
	ft_putstr_fd(": ", STDOUT_FILENO);
	ft_stack_iter(s, ft_elem_print);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	ft_checker_print(t_checker *c)
{
	ft_putchar_fd('\n', STDOUT_FILENO);
	ft_stack_print(&(c->a), "a");
	ft_stack_print(&(c->b), "b");
}
