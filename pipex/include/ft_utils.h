/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:53:41 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:22:24 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>

# define OPEN_READ			0x1
# define OPEN_WRITE_TRUNC	0x2
# define OPEN_WRITE_APPEND	0x4

void	ft_dup2(int oldfd, int newfd);
void	ft_execve(const char *cmd, char *const envp[]);
int		ft_open(const char *file, int flags);
int		ft_waitpid(pid_t pid, int options);
int		ft_unlink(const char *path);

#endif
