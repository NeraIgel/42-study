/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:30:38 by heha              #+#    #+#             */
/*   Updated: 2022/09/20 12:30:51 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include <stdbool.h>
# include "libft.h"

# define ERR_DEQ_EMPTY	"Empty deque."
# define ERR_DEQ_DATA	"Wrong deque push data."
# define ERR_DEQ_INDEX	"Wrong deque index range."
# define ERR_DEQ_MALLOC	"Can't allocate deque memory."

typedef struct s_deque
{
	t_list	*head;
	size_t	size;
}	t_deque;

void	ft_deque_create(t_deque *dq);
void	ft_deque_destroy(t_deque *dq);
void	ft_deque_clear(t_deque *dq);
void	ft_deque_error(t_deque *dq, const char *errmsg);
size_t	ft_deque_size(const t_deque *dq);
bool	ft_deque_empty(const t_deque *dq);
void	ft_deque_iter(t_deque *dq, void (*f)(void *));
void	ft_deque_push(t_deque *dq, void *content, size_t n);
void	ft_deque_pop(t_deque *dq);
void	*ft_deque_at(t_deque *dq, size_t n);
void	*ft_deque_front(t_deque *dq);
void	*ft_deque_back(t_deque *dq);

#endif
