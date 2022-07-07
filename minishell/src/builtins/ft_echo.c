/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:40:42 by heha              #+#    #+#             */
/*   Updated: 2022/07/06 14:09:26 by sihunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_builtins.h"

static int	ft_strcmp2(const char *s1, const char *s2)
{
	unsigned char	*cp2;
	int				i;

	cp2 = (unsigned char *)s2;
	i = 1;
	if (cp2 == NULL)
		return (1);
	if (*cp2 && (s1[1] != cp2[1]))
		return (1);
	while (*cp2 && (s1[1] == cp2[i]))
		i++;
	if (cp2[i] != '\0')
		return (1);
	return (0);
}

int	ft_echo_with_opt(char *const cmd[])
{
	int	i;

	i = 1;
	while (!(ft_strcmp2("-n", cmd[i])))
		i++;
	if (cmd[i] == NULL)
		return (0);
	if (!(ft_strcmp2("-n", cmd[1])))
	{
		while (cmd[i - 1])
		{
			if (!cmd[i + 1])
			{
				ft_putstr_fd(cmd[i], STDOUT_FILENO);
				break ;
			}
			ft_putstr_fd(cmd[i], STDOUT_FILENO);
			ft_putstr_fd(" ", STDOUT_FILENO);
			i++;
		}
	}
	else
		return (1);
	return (0);
}

int	ft_echo(char *const argv[], t_queue *envmap, t_builtininfo *info)
{
	int			i;

	(void)envmap;
	(void)info;
	i = 1;
	if (argv[i] == NULL)
	{
		printf("\n");
		return (0);
	}
	if (ft_echo_with_opt(argv) == 1)
	{
		while (argv[i])
		{
			if (!argv[i + 1])
			{
				printf("%s\n", argv[i]);
				break ;
			}
			printf("%s ", argv[i]);
			i++;
		}
	}
	return (0);
}
