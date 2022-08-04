/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:46:53 by heha              #+#    #+#             */
/*   Updated: 2022/07/28 12:23:52 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_core.h"
#include "ft_utils.h"

static bool	ft_error(const char *errmsg)
{
	if (errmsg)
	{
		ft_putstr_fd("\033[31;1mError:\033[0m ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	return (false);
}

static bool	ft_check_strtoi(char *str, int lower, int upper)
{
	char	*endptr;
	int		n;

	n = ft_strtoi(str, &endptr, 10);
	if (str == endptr)
		return (false);
	if (n < lower || n > upper)
		return (false);
	return (true);
}

bool	ft_args_check(int argc, char *argv[])
{
	const char	*err_count = "Invalid number of arguments.";
	const char	*err_format = "Incorrect argument format.";
	int			i;

	if (argc != 5 && argc != 6)
		return (ft_error(err_count));
	if (!ft_check_strtoi(argv[1], MIN_PHILO, MAX_PHILO))
		return (ft_error(err_format));
	i = 2;
	while (i < argc)
	{
		if (!ft_check_strtoi(argv[i], 1, INT_MAX / 1000))
			return (ft_error(err_format));
		i++;
	}
	return (true);
}
