/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:29:10 by heha              #+#    #+#             */
/*   Updated: 2022/08/03 21:12:39 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_BONUS_H
# define FT_STRUCTS_BONUS_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_thrd
{
	pthread_t	data;
	bool		initialized;
}	t_thrd;

#endif
