/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:36:16 by heha              #+#    #+#             */
/*   Updated: 2022/01/29 15:26:49 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMATTER_BONUS_H
# define FT_FORMATTER_BONUS_H

# include <stdarg.h>
# include "ft_specifier_bonus.h"

typedef struct s_formatter
{
	int	(*ft_print)(t_spec *spec, va_list ap, int fd);
}	t_formatter;

int	ft_print_formatter(t_spec *spec, va_list ap, int fd);

#endif
