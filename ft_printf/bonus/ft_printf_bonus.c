/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:12:59 by heha              #+#    #+#             */
/*   Updated: 2022/01/29 15:25:13 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vfprintf_bonus.h"

int	ft_printf(const char *fmt, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, fmt);
	ret = ft_vfprintf(1, fmt, ap);
	va_end(ap);
	return (ret);
}
