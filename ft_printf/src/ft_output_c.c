/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:32:17 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:33:35 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_output.h"

static int	ft_print(va_list ap, int fd)
{
	t_print	print;

	ft_bzero(&print, sizeof(t_print));
	print.value.i = (char)va_arg(ap, int);
	print.value_len = 1;
	write(fd, &print.value.i, print.value_len);
	return (print.value_len);
}

t_formatter	*ft_setup_c(void)
{
	static t_formatter	this;

	this.ft_print = ft_print;
	return (&this);
}
