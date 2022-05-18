/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:27:40 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:19:12 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESS_H
# define FT_PROCESS_H

# include <unistd.h>

pid_t	ft_process_create(int pipefd[]);
void	ft_process_exec(const char *cmd, char *const envp[], int in, int out);

#endif
