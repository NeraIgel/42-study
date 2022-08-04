/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:20:14 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 14:20:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_bonus.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t		len;
	ssize_t		wsize;
	const char	*buf = s;

	if (s && fd >= 0)
	{
		len = ft_strlen(s);
		while (len)
		{
			wsize = write(fd, buf, len);
			if (wsize < 0)
				return (-1);
			buf += wsize;
			len -= wsize;
		}
		return (0);
	}
	return (-1);
}
