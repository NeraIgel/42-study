/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heha <heha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:52:35 by heha              #+#    #+#             */
/*   Updated: 2022/09/25 18:04:23 by heha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE	4096

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
int		ft_strtoi(const char *str, char **endptr, int base);
double	ft_strtod(const char *str, char **endptr);
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	**ft_split2(char const *s, char c1, char c2);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(intmax_t n, int fd);
void	ft_lstinit(t_list *head);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list *head, t_list *new);
int		ft_lstsize(t_list *head);
t_list	*ft_lstfirst(t_list *head);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list *head, t_list *new);
void	ft_lstdelone(t_list *node, void (*del)(void *));
void	ft_lstclear(t_list *head, void (*del)(void *));
void	ft_lstiter(t_list *head, void (*f)(void *));
t_list	*ft_lstmap(t_list *head, void *(*f)(void *), void (*del)(void *));
int		ft_get_next_line(int fd, char **line);

#endif
