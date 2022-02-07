/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_percent_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:01:29 by heha              #+#    #+#             */
/*   Updated: 2022/02/02 13:22:36 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "libft.h"
#include "ft_output_bonus.h"
#include "ft_output_utils_bonus.h"

static void	ft_print_exec(t_print *print, int fd)
{
	ft_putpad_fd(' ', print->left_margin, fd);
	ft_putpad_fd('0', print->zero, fd);
	write(fd, &print->val.i, print->val_len);
	ft_putpad_fd(' ', print->right_margin, fd);
}

static int	ft_print(t_spec *spec, va_list ap, int fd)
{
	t_print	print;
	void	*notused;
	int		margin;

	notused = ap;
	ft_bzero(&print, sizeof(t_print));
	print.val.i = '%';
	print.val_len = 1;
	if (spec->precision == -1 && \
			spec->flags & (1U << F_ZERO) && !(spec->flags & (1U << F_MINUS)))
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

t_formatter	*ft_setup_percent(void)
{
	static t_formatter	this;

	this.ft_print = ft_print;
	return (&this);
}
