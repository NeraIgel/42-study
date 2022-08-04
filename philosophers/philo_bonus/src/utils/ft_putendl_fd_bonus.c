/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:20:32 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 14:20:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_bonus.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (s && fd >= 0)
	{
		if (ft_putstr_fd(s, fd) < 0)
			return (-1);
		if (write(fd, "\n", 1) < 0)
			return (-1);
		return (0);
	}
	return (-1);
}
