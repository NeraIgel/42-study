/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:44:27 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:41 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ELEM_H
# define FT_ELEM_H

typedef unsigned int	t_element;

void	ft_int_swap(void *e1, void *e2);
int		ft_int_compare(const void *e1, const void *e2);
int		ft_elem_compare(const void *e1, const void *e2);

#endif
