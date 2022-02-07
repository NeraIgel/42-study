/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:20:25 by heha              #+#    #+#             */
/*   Updated: 2022/02/05 16:32:41 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "libft.h"
#include "ft_formatter.h"

static int	ft_handle_non_conversion(char **s, int fd)
{
	ptrdiff_t	len;
	char		*a;
	char		*z;

	a = *s;
	while (**s && (**s != '%'))
		(*s)++;
	z = *s;
	while (**s && (*s)[0] == '%' && (*s)[1] == '%')
	{
		z++;
		(*s) += 2;
	}
	len = z - a;
	if (len)
		write(fd, a, len);
	return ((int)len);
}

static int	ft_handle_conversion(char **s, va_list ap, int fd)
{
	t_spec	spec;

	(*s)++;
	ft_bzero(&spec, sizeof(t_spec));
	if (ft_parse_specifier(&spec, s) < 0)
		return (-1);
	return (ft_print_formatter(&spec, ap, fd));
}

static int	ft_printf_core(int fd, const char *fmt, va_list ap)
{
	int		cnt;
	int		ret;
	char	*s;

	cnt = 0;
	s = (char *)fmt;
	while (*s)
	{
		ret = ft_handle_non_conversion(&s, fd);
		cnt += ret;
		if (ret)
			continue ;
		ret = ft_handle_conversion(&s, ap, fd);
		if (ret < 0)
			return (-1);
		cnt += ret;
	}
	return (cnt);
}

int	ft_vfprintf(int fd, const char *fmt, va_list ap)
{
	if (fd < 0 || !fmt || !ap)
		return (-1);
	return (ft_printf_core(fd, fmt, ap));
}
