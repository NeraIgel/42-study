/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:31:22 by heha              #+#    #+#             */
/*   Updated: 2022/06/12 19:00:27 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnl_without_newline(int fd, char **line)
{
	int		ret;
	size_t	len;

	ret = ft_get_next_line(fd, line);
	if (ret <= 0)
		return (ret);
	len = 0;
	if (*line)
		len = ft_strlen(*line);
	if (len && (*line)[len - 1] == '\n')
		(*line)[len - 1] = '\0';
	return (ret);
}
