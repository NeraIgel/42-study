/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:36:28 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:33:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_output.h"

static int	ft_print(va_list ap, int fd)
{
	t_print	print;
	void	*p;

	ft_bzero(&print, sizeof(t_print));
	p = va_arg(ap, char *);
	if (!p)
		p = NULL_STR;
	print.value.p = p;
	print.value_len = ft_strlen(p);
	write(fd, print.value.p, print.value_len);
	return (print.value_len);
}

t_formatter	*ft_setup_s(void)
{
	static t_formatter	this;

	this.ft_print = ft_print;
	return (&this);
}
