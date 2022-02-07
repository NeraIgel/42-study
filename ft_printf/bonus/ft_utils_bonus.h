/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:54:44 by heha              #+#    #+#             */
/*   Updated: 2022/01/29 15:29:40 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_BONUS_H
# define FT_UTILS_BONUS_H

# include <stdint.h>

void	ft_putnbr_base_fd(uintmax_t n, int base, _Bool uppercase, int fd);
int		ft_nbrlen_base(uintmax_t n, int base);
int		ft_getnbr_base(char **s, int base);

#endif
