/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:41:52 by heha              #+#    #+#             */
/*   Updated: 2022/02/08 15:55:32 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*cp;
	char		find;

	cp = s;
	find = (char)c;
	while (1)
	{
		if (*cp == find)
			return ((char *)cp);
		if (*cp == '\0')
			break ;
		cp++;
	}
	return (NULL);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (n + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, n + 1);
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	new = NULL;
	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (!new)
			return (NULL);
		if (ft_strlcpy(new, s1, len1 + 1) >= (len1 + 1))
			return (NULL);
		if (ft_strlcpy(new + len1, s2, len2 + 1) >= (len2 + 1))
			return (NULL);
	}
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = 0;
	while (*src && (src_len + 1 < dstsize))
	{
		*dst++ = *src++;
		src_len++;
	}
	while (*src++)
		src_len++;
	if (dstsize)
		*dst = '\0';
	return (src_len);
}
