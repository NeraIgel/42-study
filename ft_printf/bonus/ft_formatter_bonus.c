/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:38:34 by heha              #+#    #+#             */
/*   Updated: 2022/01/29 15:26:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_output_bonus.h"

int	ft_print_formatter(t_spec *spec, va_list ap, int fd)
{
	static	t_formatter	*(*tbl[MAX_TYPE])(void) = {\
		ft_setup_c, ft_setup_s, ft_setup_p, ft_setup_i, \
			ft_setup_i, ft_setup_ui, ft_setup_x, ft_setup_ux, \
			ft_setup_percent};

	return ((tbl[spec->type]())->ft_print(spec, ap, fd));
}
