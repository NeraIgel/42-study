/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:20:49 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 14:21:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_bonus.h"

static void	ft_putnbr_sub(uintmax_t nb, int fd)
{
	if (nb > 9)
		ft_putnbr_sub(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

void	ft_putnbr_fd(intmax_t n, int fd)
{
	uintmax_t	nb;

	if (fd >= 0)
	{
		nb = n;
		if (n < 0)
		{
			nb *= -1;
			ft_putchar_fd('-', fd);
		}
		ft_putnbr_sub(nb, fd);
	}
}
