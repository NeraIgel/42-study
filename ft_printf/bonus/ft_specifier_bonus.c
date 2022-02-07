/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:29:42 by heha              #+#    #+#             */
/*   Updated: 2022/01/29 15:26:44 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_utils_bonus.h"
#include "ft_specifier_bonus.h"

static int	ft_parse_flags(t_spec *spec, char **s)
{
	char	*find;

	while (**s)
	{
		find = ft_strchr(SPEC_FLAG, **s);
		if (!find)
			break ;
		spec->flags |= 1U << (find - SPEC_FLAG);
		(*s)++;
	}
	return (0);
}

static int	ft_parse_width(t_spec *spec, char **s)
{
	int		width;

	width = ft_getnbr_base(s, 10);
	if (width < 0)
		return (-1);
	spec->width = width;
	return (0);
}

static int	ft_parse_precision(t_spec *spec, char **s)
{
	int		precision;

	spec->precision = -1;
	if (**s == '.')
	{
		(*s)++;
		precision = ft_getnbr_base(s, 10);
		if (precision < 0)
			return (-1);
		spec->precision = precision;
	}
	return (0);
}

static int	ft_parse_type(t_spec *spec, char **s)
{
	char	*find;
	t_type	type;

	find = ft_strchr(SPEC_TYPE, **s);
	if (!find)
		return (-1);
	type = find - SPEC_TYPE;
	if (type == 4)
		type = T_INT;
	spec->type = type;
	(*s)++;
	return (0);
}

int	ft_parse_specifier(t_spec *spec, char **s)
{
	if (ft_parse_flags(spec, s) < 0)
		return (-1);
	if (ft_parse_width(spec, s) < 0)
		return (-1);
	if (ft_parse_precision(spec, s) < 0)
		return (-1);
	if (ft_parse_type(spec, s) < 0)
		return (-1);
	return (0);
}
