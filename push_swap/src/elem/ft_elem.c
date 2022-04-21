/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:45:30 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:47 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_elem.h"

void	ft_int_swap(void *e1, void *e2)
{
	int		*p1;
	int		*p2;
	int		tmp;

	p1 = (int *)e1;
	p2 = (int *)e2;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int	ft_int_compare(const void *e1, const void *e2)
{
	int		n1;
	int		n2;

	n1 = *(int *)e1;
	n2 = *(int *)e2;
	if (n1 < n2)
		return (-1);
	else
		return (n1 > n2);
}

int	ft_elem_compare(const void *e1, const void *e2)
{
	t_element	n1;
	t_element	n2;

	n1 = *(t_element *)e1;
	n2 = *(t_element *)e2;
	if (n1 < n2)
		return (-1);
	else
		return (n1 > n2);
}
