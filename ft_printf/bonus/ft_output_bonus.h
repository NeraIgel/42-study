/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:39:28 by heha              #+#    #+#             */
/*   Updated: 2022/01/29 15:27:02 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTPUT_BONUS_H
# define FT_OUTPUT_BONUS_H

# include <stdint.h>
# include "ft_formatter_bonus.h"

# define NULL_STR	"(null)"

typedef union u_arg
{
	uintmax_t	i;
	void		*p;
}	t_arg;

typedef struct s_print
{
	int		left_margin;
	int		sign;
	int		prefix;
	int		zero;
	t_arg	val;
	int		val_len;
	int		right_margin;
}	t_print;

t_formatter	*ft_setup_c(void);
t_formatter	*ft_setup_s(void);
t_formatter	*ft_setup_p(void);
t_formatter	*ft_setup_i(void);
t_formatter	*ft_setup_ui(void);
t_formatter	*ft_setup_x(void);
t_formatter	*ft_setup_ux(void);
t_formatter	*ft_setup_percent(void);

#endif
