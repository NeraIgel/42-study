/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:47:41 by heha              #+#    #+#             */
/*   Updated: 2022/07/25 13:47:51 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_mutex
{
	pthread_mutex_t	data;
	bool			initialized;
}	t_mutex;

typedef struct s_thread
{
	pthread_t	data;
	bool		initialized;
}	t_thread;

#endif
