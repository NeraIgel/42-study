/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:04:04 by heha              #+#    #+#             */
/*   Updated: 2021/12/20 16:23:14 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_sub(unsigned int nb, int fd)
{
	if (nb > 9)
		ft_putnbr_sub(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

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
