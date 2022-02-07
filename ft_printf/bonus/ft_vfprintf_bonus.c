/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:16:03 by heha              #+#    #+#             */
/*   Updated: 2022/02/05 16:32:11 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "libft.h"
#include "ft_formatter_bonus.h"

static int	ft_handle_non_conversion(char **s, int fd)
{
	ptrdiff_t	len;
	char		*a;
	char		*z;

	a = *s;
	while (**s && (**s != '%'))
		(*s)++;
	z = *s;
	len = z - a;
	if (fd && len)
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

static int	ft_printf_core(int fd, const char *fmt, va_list ap, int max_arg)
{
	int		cnt;
	int		arg;
	int		ret;
	char	*s;

	cnt = 0;
	arg = 0;
	s = (char *)fmt;
	while (*s && (arg <= max_arg))
	{
		ret = ft_handle_non_conversion(&s, fd);
		cnt += ret;
		if (ret)
			continue ;
		ret = ft_handle_conversion(&s, ap, fd);
		cnt += ret;
		arg++;
	}
	return (cnt);
}

static _Bool	ft_check_error(const char *fmt, va_list ap, int *max_arg)
{
	char	*s;
	va_list	ap2;

	*max_arg = 0;
	s = (char *)fmt;
	va_copy(ap2, ap);
	while (*s)
	{
		if (ft_handle_non_conversion(&s, 0))
			continue ;
		if (ft_handle_conversion(&s, ap2, 0) < 0)
		{
			(*max_arg)--;
			va_end(ap2);
			return (1);
		}
		(*max_arg)++;
	}
	va_end(ap2);
	return (0);
}

int	ft_vfprintf(int fd, const char *fmt, va_list ap)
{
	int		max_arg;

	if (fd < 0 || !fmt || !ap)
		return (-1);
	if (ft_check_error(fmt, ap, &max_arg))
	{
		ft_printf_core(fd, fmt, ap, max_arg);
		return (-1);
	}
	else
		return (ft_printf_core(fd, fmt, ap, max_arg));
}
