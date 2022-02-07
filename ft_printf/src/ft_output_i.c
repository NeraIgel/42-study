/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:47:09 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:33:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_utils.h"
#include "ft_output.h"

static int	ft_print(va_list ap, int fd)
{
	t_print		print;
	intmax_t	n;

	ft_bzero(&print, sizeof(t_print));
	n = va_arg(ap, int);
	if (n < 0)
	{
		print.sign = 1;
		print.value.i = n * -1;
	}
	else
		print.value.i = n;
	print.value_len = ft_nbrlen_base(print.value.i, 10);
	write(fd, "-", print.sign);
	ft_putnbr_base_fd(print.value.i, 10, 0, fd);
	return (print.sign + print.value_len);
}

t_formatter	*ft_setup_i(void)
{
	static t_formatter	this;

	this.ft_print = ft_print;
	return (&this);
}
