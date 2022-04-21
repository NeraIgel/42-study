/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:47:02 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:42:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSTR_H
# define FT_INSTR_H

# include "ft_stack.h"

# define MAX_INSTR	11

typedef char *	t_instr;

typedef struct s_instrtbl
{
	const t_instr	instr;
	void			(*ft)(t_stack *, t_stack *);
}	t_instrtbl;

void	ft_instr_sa(t_stack *a, t_stack *b);
void	ft_instr_sb(t_stack *a, t_stack *b);
void	ft_instr_ss(t_stack *a, t_stack *b);
void	ft_instr_pa(t_stack *a, t_stack *b);
void	ft_instr_pb(t_stack *a, t_stack *b);
void	ft_instr_ra(t_stack *a, t_stack *b);
void	ft_instr_rb(t_stack *a, t_stack *b);
void	ft_instr_rr(t_stack *a, t_stack *b);
void	ft_instr_rra(t_stack *a, t_stack *b);
void	ft_instr_rrb(t_stack *a, t_stack *b);
void	ft_instr_rrr(t_stack *a, t_stack *b);

#endif
