/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:49:26 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:33:55 by heha             ###   ########.fr       */
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
	print.value_len = ft_nbrlen_base(print.value.i, 10);
	ft_putnbr_base_fd(print.value.i, 10, 0, fd);
	return (print.value_len);
}

t_formatter	*ft_setup_ui(void)
{
	static t_formatter	this;

	this.ft_print = ft_print;
	return (&this);
}
