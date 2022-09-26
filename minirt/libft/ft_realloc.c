/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:22:35 by heha              #+#    #+#             */
/*   Updated: 2022/09/19 20:25:51 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t count, size_t size)
{
	void	*new;

	if (size && SIZE_MAX / size < count)
		return (NULL);
	new = (void *)malloc(size * count);
	if (!new)
		return (NULL);
	if (ptr && count > 0)
		ft_memcpy(new, ptr, size * (count - 1));
	free(ptr);
	return (new);
}
