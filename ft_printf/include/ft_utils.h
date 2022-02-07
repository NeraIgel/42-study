/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:58:31 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:34:22 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdint.h>

void	ft_putnbr_base_fd(uintmax_t n, int base, _Bool uppercase, int fd);
int		ft_nbrlen_base(uintmax_t n, int base);

#endif
