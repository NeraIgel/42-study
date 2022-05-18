/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outfile_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:31:10 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 16:58:31 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_utils.h"

int	ft_outfile(const char *outfile, bool heredoc)
{
	if (heredoc)
		return (ft_open(outfile, OPEN_WRITE_APPEND));
	else
		return (ft_open(outfile, OPEN_WRITE_TRUNC));
}
