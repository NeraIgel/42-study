/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:51:42 by heha              #+#    #+#             */
/*   Updated: 2021/12/22 13:03:00 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

static int	ft_check_sign(char c, int *sign)
{
	if (c == '+')
	{
		*sign *= 1;
		return (1);
	}
	else if (c == '-')
	{
		*sign *= -1;
		return (1);
	}
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	n;
	unsigned long	prev;
	int				sign;

	n = 0L;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str && ft_check_sign(*str, &sign))
		str++;
	while (*str && ft_isdigit(*str))
	{
		prev = n;
		n = (*str - '0') + n * 10;
		if (prev != (n - (*str - '0')) / 10)
		{
			if (sign < 0)
				return ((int)LONG_MIN);
			else
				return ((int)LONG_MAX);
		}
		str++;
	}
	return (sign * (int)n);
}
