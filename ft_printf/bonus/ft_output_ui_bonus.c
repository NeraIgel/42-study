/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_ui_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:59:10 by heha              #+#    #+#             */
/*   Updated: 2022/02/02 13:04:28 by heha             ###   ########.fr       */
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
	ft_putpad_fd('0', print->zero, fd);
	if (print->val_len)
		ft_putnbr_base_fd(print->val.i, 10, 0, fd);
	ft_putpad_fd(' ', print->right_margin, fd);
}

static int	ft_print(t_spec *spec, va_list ap, int fd)
{
	t_print	print;
	int		margin;

	ft_bzero(&print, sizeof(t_print));
	print.val.i = va_arg(ap, unsigned int);
	print.val_len = ft_nbrlen_base(print.val.i, 10);
	if (spec->precision == 0 && print.val.i == 0)
		print.val_len = 0;
	if (spec->precision != -1)
		print.zero = ft_max(spec->precision - print.val_len, 0);
	else if ((spec->flags & (1U << F_ZERO)) && !(spec->flags & (1U << F_MINUS)))
		print.zero = ft_max(spec->width - print.val_len, 0);
	margin = ft_max(spec->width - print.zero - print.val_len, 0);
	if (spec->flags & (1U << F_MINUS))
		print.right_margin = margin;
	else
		print.left_margin = margin;
	if ((uintmax_t)print.zero + print.val_len + margin >= INT_MAX)
		return (-1);
	if (fd)
		ft_print_exec(&print, fd);
	return (print.zero + print.val_len + margin);
}

t_formatter	*ft_setup_ui(void)
{
	static t_formatter	this;

	this.ft_print = ft_print;
	return (&this);
}
