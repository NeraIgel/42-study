/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:40:15 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:26 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include "libft.h"

# define ERR_QUE_EMPTY	"\033[31;1mError:\033[0m Empty queue."
# define ERR_QUE_DATA	"\033[31;1mError:\033[0m Wrong queue push data."
# define ERR_QUE_MALLOC	"\033[31;1mError:\033[0m Can't allocate queue memory."

typedef struct s_queue
{
	t_list	head;
	size_t	size;
}	t_queue;

void	ft_queue_init(t_queue *q);
void	ft_queue_clear(t_queue *q);
void	ft_queue_error(t_queue *q, char *errmsg);
size_t	ft_queue_size(const t_queue *q);
bool	ft_queue_empty(const t_queue *q);
void	ft_queue_iter(t_queue *q, void (*f)(void *));
void	ft_queue_push(t_queue *q, void *content, size_t n);
void	ft_queue_pop(t_queue *q);
void	*ft_queue_front(t_queue *q);
void	*ft_queue_rear(t_queue *q);

#endif
