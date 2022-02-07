/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:41:33 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:32:24 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMATTER_H
# define FT_FORMATTER_H

# include <stdarg.h>
# include "ft_specifier.h"

typedef struct s_formatter
{
	int	(*ft_print)(va_list ap, int fd);
}	t_formatter;

int	ft_print_formatter(t_spec *spec, va_list ap, int fd);

#endif
