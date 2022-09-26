/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:59:51 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 18:02:04 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_tblsize(char const *s, char c1, char c2)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		while (*s && (*s == c1 || *s == c2))
			s++;
		if (*s == '\0')
			break ;
		size++;
		while (*s && (*s != c1 && *s != c2))
			s++;
	}
	return (size);
}

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

static char	**ft_split_sub(char **tbl, char const *s, char c1, char c2)
{
	char		**cp;
	char const	*begin;

	cp = tbl;
	while (*s)
	{
		while (*s && (*s == c1 || *s == c2))
			s++;
		if (*s == '\0')
			break ;
		begin = s;
		while (*s && (*s != c1 && *s != c2))
			s++;
		*cp = (char *)malloc(sizeof(char) * (s - begin + 1));
		if (!(*cp))
		{
			ft_tblclear(tbl);
			return (NULL);
		}
		ft_strlcpy(*cp, begin, s - begin + 1);
		cp++;
	}
	*cp = NULL;
	return (tbl);
}

char	**ft_split2(char const *s, char c1, char c2)
{
	char	**tbl;
	size_t	size;

	tbl = NULL;
	if (s)
	{
		size = ft_tblsize(s, c1, c2);
		tbl = (char **)malloc(sizeof(char *) * (size + 1));
		if (!tbl)
			return (NULL);
		tbl = ft_split_sub(tbl, s, c1, c2);
		if (!tbl)
			return (NULL);
	}
	return (tbl);
}
