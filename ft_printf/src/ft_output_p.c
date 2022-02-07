/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:44:31 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:33:48 by heha             ###   ########.fr       */
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
	print.prefix = 2;
	print.value.i = (uintmax_t)va_arg(ap, void *);
	print.value_len = ft_nbrlen_base(print.value.i, 16);
	write(fd, "0x", print.prefix);
	ft_putnbr_base_fd(print.value.i, 16, 0, fd);
	return (print.prefix + print.value_len);
}

t_formatter	*ft_setup_p(void)
{
	static t_formatter	this;

	this.ft_print = ft_print;
	return (&this);
}
