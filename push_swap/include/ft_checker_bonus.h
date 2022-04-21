/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:55:22 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:42:28 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_BONUS_H
# define FT_CHECKER_BONUS_H

# include "ft_stack.h"

# define ERR_CHECKER	"\033[31;1mError\033[0m"

typedef struct s_checker
{
	t_stack	a;
	t_stack	b;
	t_stack	input;
}	t_checker;

void	ft_checker_init(t_checker *c);
void	ft_checker_clear(t_checker *c);
void	ft_checker_error(t_checker *c, char *errmsg);
void	ft_checker_setup(t_checker *c, int argc, char **argv);
void	ft_checker_routine(t_checker *c);
void	ft_checker_print(t_checker *c);

#endif
