/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:48:16 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:33:28 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTPUT_H
# define FT_OUTPUT_H

# include <stdint.h>
# include "ft_formatter.h"

# define NULL_STR	"(null)"

typedef union u_arg
{
	uintmax_t	i;
	void		*p;
}	t_arg;

typedef struct s_print
{
	int		sign;
	int		prefix;
	t_arg	value;
	int		value_len;
}	t_print;

t_formatter	*ft_setup_c(void);
t_formatter	*ft_setup_s(void);
t_formatter	*ft_setup_p(void);
t_formatter	*ft_setup_i(void);
t_formatter	*ft_setup_ui(void);
t_formatter	*ft_setup_x(void);
t_formatter	*ft_setup_ux(void);

#endif
