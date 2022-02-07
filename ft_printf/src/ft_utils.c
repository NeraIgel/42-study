/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:20:03 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:34:29 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

static void	ft_putnbr_exec(uintmax_t n, char *base, uintmax_t notation, int fd)
{
	if (n > (notation - 1))
		ft_putnbr_exec(n / notation, base, notation, fd);
	write(fd, &base[n % notation], 1);
}

void	ft_putnbr_base_fd(uintmax_t n, int base, _Bool uppercase, int fd)
{
	if (base == 10)
		ft_putnbr_exec(n, "0123456789", base, fd);
	else if (base == 16 && !uppercase)
		ft_putnbr_exec(n, "0123456789abcdef", base, fd);
	else
		ft_putnbr_exec(n, "0123456789ABCDEF", base, fd);
}

int	ft_nbrlen_base(uintmax_t n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}
