/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:00:29 by heha              #+#    #+#             */
/*   Updated: 2022/02/02 16:24:51 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "libft.h"
#include "ft_utils_bonus.h"
#include "ft_output_bonus.h"
#include "ft_output_utils_bonus.h"

static void	ft_print_exec(t_print *print, int fd)
{
	ft_putpad_fd(' ', print->left_margin, fd);
	write(fd, "0x", print->prefix);
	ft_putpad_fd('0', print->zero, fd);
	if (print->val_len)
		ft_putnbr_base_fd(print->val.i, 16, 0, fd);
	ft_putpad_fd(' ', print->right_margin, fd);
}

static int	ft_print(t_spec *spec, va_list ap, int fd)
{
	t_print	pt;
	int		margin;

	ft_bzero(&pt, sizeof(t_print));
	pt.val.i = va_arg(ap, unsigned int);
	pt.val_len = ft_nbrlen_base(pt.val.i, 16);
	if ((spec->flags & (1U << F_HASH)) && pt.val.i)
		pt.prefix = 2;
	if (spec->precision == 0 && pt.val.i == 0)
		pt.val_len = 0;
	if (spec->precision != -1)
		pt.zero = ft_max(spec->precision - pt.val_len, 0);
	else if ((spec->flags & (1U << F_ZERO)) && !(spec->flags & (1U << F_MINUS)))
		pt.zero = ft_max(spec->width - pt.prefix - pt.val_len, 0);
	margin = ft_max(spec->width - pt.prefix - pt.zero - pt.val_len, 0);
	if (spec->flags & (1U << F_MINUS))
		pt.right_margin = margin;
	else
		pt.left_margin = margin;
	if ((uintmax_t)pt.prefix + pt.zero + pt.val_len + margin >= INT_MAX)
		return (-1);
	if (fd)
		ft_print_exec(&pt, fd);
	return (pt.prefix + pt.zero + pt.val_len + margin);
}

t_formatter	*ft_setup_x(void)
{
	static t_formatter	this;

	this.ft_print = ft_print;
	return (&this);
}
