/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_ux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:48:30 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:34:07 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_utils.h"
#include "ft_output.h"

static int	ft_print(va_list ap, int fd)
{
	t_print	print;

	ft_bzero(&print, sizeof(t_print));
	print.value.i = va_arg(ap, unsigned int);
	print.value_len = ft_nbrlen_base(print.value.i, 16);
	ft_putnbr_base_fd(print.value.i, 16, 1, fd);
	return (print.value_len);
}

t_formatter	*ft_setup_ux(void)
{
	static t_formatter	this;

	this.ft_print = ft_print;
	return (&this);
}
