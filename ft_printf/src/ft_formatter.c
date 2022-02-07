/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:51:53 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:32:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output.h"

int	ft_print_formatter(t_spec *spec, va_list ap, int fd)
{
	static	t_formatter	*(*tbl[MAX_TYPE])(void) = {\
		ft_setup_c, ft_setup_s, ft_setup_p, ft_setup_i, \
			ft_setup_i, ft_setup_ui, ft_setup_x, ft_setup_ux};

	return ((tbl[spec->type]())->ft_print(ap, fd));
}
