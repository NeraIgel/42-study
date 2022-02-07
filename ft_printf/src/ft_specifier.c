/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:36:35 by heha              #+#    #+#             */
/*   Updated: 2022/01/26 15:31:23 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_specifier.h"

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
	if (ft_parse_type(spec, s) < 0)
		return (-1);
	return (0);
}
