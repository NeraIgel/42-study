/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:43:16 by heha              #+#    #+#             */
/*   Updated: 2022/05/17 11:26:42 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	ft_tblclear(char **tbl)
{
	char	**cp;

	cp = tbl;
	while (*cp)
	{
		free(*cp);
		cp++;
	}
	free(tbl);
	tbl = NULL;
}

static char	*ft_findcommand(const char *cmd, char *const tbl[])
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	while (tbl[i])
	{
		tmp = ft_strjoin(tbl[i], "/");
		if (!tmp)
			return (NULL);
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!path)
			return (NULL);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return ((char *)cmd);
}

static char	*ft_getpath(const char *cmd, char *const envp[])
{
	char	**tbl;
	char	*path;

	if (cmd && !ft_strchr(cmd, '/'))
	{
		while (*envp && ft_strncmp(*envp, "PATH=", 5))
			envp++;
		if (*envp)
		{
			tbl = ft_split(*envp + 5, ':');
			if (!tbl)
				return (NULL);
			path = ft_findcommand(cmd, tbl);
			ft_tblclear(tbl);
			return (path);
		}
	}
	return ((char *)cmd);
}

static void	ft_error(const char *errmsg, const char *path, int ret)
{
	if (errmsg && path)
	{
		ft_putstr_fd("\033[31;1mError: \033[0m", STDERR_FILENO);
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd((char *)errmsg, STDERR_FILENO);
	}
	else
		perror(errmsg);
	exit(ret);
}

void	ft_execve(const char *cmd, char *const envp[])
{
	char	*path;
	char	**argv;

	argv = ft_split(cmd, ' ');
	if (!argv)
		ft_error("malloc", NULL, EXIT_FAILURE);
	if (!argv[0])
		ft_error("command not found", cmd, 127);
	path = ft_getpath(argv[0], envp);
	if (!path)
		ft_error("malloc", NULL, EXIT_FAILURE);
	if (execve(path, argv, envp) < 0)
		ft_error("command not found", path, 127);
}
