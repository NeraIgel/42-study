#include <stdlib.h>
#include "ft_list.h"

void	ft_lstinit(t_list *head)
{
	head->content = NULL;
	head->prev = head;
	head->next = head;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstfirst(const t_list *head)
{
	if (head == head->next)
		return (NULL);
	return (head->next);
}

t_list	*ft_lstlast(const t_list *head)
{
	if (head == head->prev)
		return (NULL);
	return (head->prev);
}

void	ft_lstadd_back(t_list *head, t_list *new)
{
	t_list	*tail;

	tail = head->prev;
	if (new)
	{
		new->prev = tail;
		new->next = tail->next;
		tail->next->prev = new;
		tail->next = new;
	}
}

void	ft_lstdelone(t_list *node, void (*del)(void *))
{
	if (node)
	{
		if (del)
			del(node->content);
		node->next->prev = node->prev;
		node->prev->next = node->next;
		free(node);
	}
}

void	ft_lstclear(t_list *head, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	node = head->next;
	while (node != head)
	{
		next = node->next;
		ft_lstdelone(node, del);
		node = next;
	}
}
