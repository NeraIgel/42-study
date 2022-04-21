/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:58:54 by heha              #+#    #+#             */
/*   Updated: 2022/04/14 13:30:55 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *head)
{
	size_t	size;
	t_list	*node;

	size = 0U;
	node = head->next;
	while (node != head)
	{
		size++;
		node = node->next;
	}
	return (size);
}
