/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlink_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:30:52 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:35:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_unlink(const char *path)
{
	int		ret;

	if (access(path, F_OK) < 0)
	{
		perror("access");
		return (-1);
	}
	ret = unlink(path);
	if (ret < 0)
		perror("unlink");
	return (ret);
}
