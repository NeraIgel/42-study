/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:38:49 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 13:45:25 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static void	ft_endptr_update(char **endptr, const char *str, \
		const char *cp1, const char *cp2)
{
	if (endptr)
	{
		if (cp1 == cp2)
			*endptr = (char *)str;
		else
			*endptr = (char *)cp2;
	}
}

int	ft_strtoi(const char *str, char **endptr)
{
	unsigned long long	n;
	int					sign;
	const char			*cp1 = str;
	const char			*cp2 = str;

	n = 0ULL;
	sign = 1;
	while (*cp1 && ft_isspace(*cp1))
		cp1++;
	if (*cp1 == '-' || *cp1 == '+')
		if (*cp1++ == '-')
			sign = -1;
	cp2 = cp1;
	while (*cp2 && ft_isdigit(*cp2))
	{
		n = (*cp2 - '0') + n * 10;
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && n && n - 1 > INT_MAX))
		{
			cp2 = cp1;
			break ;
		}
		cp2++;
	}
	ft_endptr_update(endptr, str, cp1, cp2);
	return (sign * (int)n);
}
