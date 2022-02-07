/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:19:33 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:30:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VFPRINTF_H
# define FT_VFPRINTF_H

# include <stdarg.h>

int	ft_vfprintf(int fd, const char *fmt, va_list ap);

#endif
