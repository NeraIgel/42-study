/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:18:18 by heha              #+#    #+#             */
/*   Updated: 2022/04/20 18:41:01 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"

# define ERR_STK_EMPTY	"\033[31;1mError:\033[0m Empty stack."
# define ERR_STK_DATA	"\033[31;1mError:\033[0m Wrong stack push data."
# define ERR_STK_MALLOC	"\033[31;1mError:\033[0m Can't allocate stack memory."
# define ERR_STK_FIND	"\033[31;1mError:\033[0m Can't found index in stack."
# define ERR_STK_FUNC	"\033[31;1mError:\033[0m Unable to perform stack func."

typedef struct s_stack
{
	t_list	head;
	size_t	size;
	int		(*cmp)(const void *, const void *);
	void	(*swap)(void *, void *);
}	t_stack;

void	ft_stack_init(t_stack *s, \
		int (*cmp)(const void *, const void *), void (*swap)(void *, void *));
void	ft_stack_clear(t_stack *s);
void	ft_stack_error(t_stack *s, char *errmsg);
size_t	ft_stack_size(const t_stack *s);
bool	ft_stack_empty(const t_stack *s);
void	ft_stack_iter(t_stack *s, void (*f)(void *));
void	ft_stack_push(t_stack *s, void *content, size_t n);
void	ft_stack_push_back(t_stack *s, void *content, size_t n);
void	ft_stack_pop(t_stack *s);
void	*ft_stack_top(t_stack *s);
void	ft_stack_swap(t_stack *s);
void	ft_stack_rotate(t_stack *s);
void	ft_stack_reverse_rotate(t_stack *s);
bool	ft_stack_check_dist(t_stack *s);
bool	ft_stack_check_sort(t_stack *s);
size_t	ft_stack_get_minidx(t_stack *s);
size_t	ft_stack_get_maxidx(t_stack *s);
void	ft_stack_sort(t_stack *s);
size_t	ft_stack_get_idx(t_stack *s, void *content);
void	ft_stack_copy(t_stack *dst, const t_stack *src, size_t n);

#endif
