/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:31:06 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:31:21 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPECIFIER_H
# define FT_SPECIFIER_H

# define SPEC_TYPE	"cspdiuxX"
# define MAX_TYPE	8

typedef enum e_type
{
	T_CHAR,
	T_STR,
	T_PTR,
	T_INT,
	T_UINT = 5,
	T_HEXA,
	T_UHEXA
}	t_type;

typedef struct s_spec
{
	t_type	type;
}	t_spec;

int	ft_parse_specifier(t_spec *spec, char **s);

#endif
