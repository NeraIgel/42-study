/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:18:59 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 14:19:11 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	int		diff;

	diff = 'a' - 'A';
	if (c >= 'A' && c <= 'Z')
		c += diff;
	return (c);
}
