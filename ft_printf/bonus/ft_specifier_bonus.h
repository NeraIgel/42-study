/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:23:49 by heha              #+#    #+#             */
/*   Updated: 2022/01/29 15:26:41 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPECIFIER_BONUS_H
# define FT_SPECIFIER_BONUS_H

# define SPEC_FLAG	"-0# +"
# define SPEC_TYPE	"cspdiuxX%"
# define MAX_TYPE	9

typedef enum e_flag
{
	F_MINUS,
	F_ZERO,
	F_HASH,
	F_SPACE,
	F_PLUS
}	t_flag;

typedef enum e_type
{
	T_CHAR,
	T_STR,
	T_PTR,
	T_INT,
	T_UINT = 5,
	T_HEXA,
	T_UHEXA,
	T_PERCENT
}	t_type;

typedef struct s_spec
{
	unsigned char	flags;
	int				width;
	int				precision;
	t_type			type;
}	t_spec;

int	ft_parse_specifier(t_spec *spec, char **s);

#endif
