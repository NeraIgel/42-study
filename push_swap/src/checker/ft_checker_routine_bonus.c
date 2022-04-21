/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_routine_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:58:04 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:42:56 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_instr.h"
#include "ft_checker_bonus.h"

static t_instrtbl	*ft_instr_lookup(t_instr instr)
{
	static t_instrtbl	tbl[MAX_INSTR + 1] = {\
		{"rra", ft_instr_rra}, {"rrb", ft_instr_rrb}, {"rrr", ft_instr_rrr}, \
		{"ra", ft_instr_ra}, {"rb", ft_instr_rb}, {"rr", ft_instr_rr}, \
		{"sa", ft_instr_sa}, {"sb", ft_instr_sb}, {"ss", ft_instr_ss}, \
		{"pa", ft_instr_pa}, {"pb", ft_instr_pb}, \
		{NULL, NULL}};
	t_instrtbl			*p;

	p = tbl;
	while (p->instr)
	{
		if (!ft_strcmp(instr, p->instr))
			return (p);
		p++;
	}
	return (NULL);
}

static bool	ft_checker_complete(t_checker *c)
{
	if (!ft_stack_check_sort(&(c->a)))
		return (false);
	if (!ft_stack_empty(&(c->b)))
		return (false);
	return (true);
}

static bool	ft_checker_perform(t_checker *c)
{
	t_instr		instr;
	size_t		len;
	t_instrtbl	*p;

	instr = ft_get_next_line(STDIN_FILENO);
	if (!instr)
		return (false);
	len = ft_strlen(instr);
	if (len && instr[len - 1] == '\n')
		instr[len - 1] = '\0';
	p = ft_instr_lookup(instr);
	free(instr);
	if (!p)
		ft_checker_error(c, ERR_CHECKER);
	p->ft(&(c->a), &(c->b));
	return (true);
}

static void	ft_checker_result(t_checker *c)
{
	if (ft_checker_complete(c))
		ft_putendl_fd("\033[32;1mOK\033[0m", STDOUT_FILENO);
	else
		ft_putendl_fd("\033[31;1mKO\033[0m", STDOUT_FILENO);
}

void	ft_checker_routine(t_checker *c)
{
	while (ft_checker_perform(c))
		;
	ft_checker_result(c);
}
