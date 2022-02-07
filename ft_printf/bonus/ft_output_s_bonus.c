/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:50:14 by heha              #+#    #+#             */
/*   Updated: 2022/02/02 13:03:28 by heha             ###   ########.fr       */
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
	write(fd, print->val.p, print->val_len);
	ft_putpad_fd(' ', print->right_margin, fd);
}

static int	ft_print(t_spec *spec, va_list ap, int fd)
{
	t_print	print;
	void	*p;
	int		margin;

	ft_bzero(&print, sizeof(t_print));
	p = va_arg(ap, char *);
	if (!p)
		p = NULL_STR;
	print.val.p = p;
	print.val_len = ft_strlen(p);
	if (spec->precision != -1 && spec->precision < print.val_len)
		print.val_len = spec->precision;
	margin = ft_max(spec->width - print.val_len, 0);
	if (spec->flags & (1U << F_MINUS))
		print.right_margin = margin;
	else
		print.left_margin = margin;
	if ((uintmax_t)print.val_len + margin >= INT_MAX)
		return (-1);
	if (fd)
		ft_print_exec(&print, fd);
	return (print.val_len + margin);
}

t_formatter	*ft_setup_s(void)
{
	static t_formatter	this;

	this.ft_print = ft_print;
	return (&this);
}
