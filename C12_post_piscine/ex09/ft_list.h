#ifndef	FT_LIST_H
# define FT_LIST_H

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct		s_list
{
    struct s_list	*next;
    void 		*data;
}			t_list;

t_list	*ft_create_elem(void *data)
{
    t_list	*new;

    new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
	    return NULL;
    new->data = data;
    new->next = NULL;
    return	(new);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
    t_list	*new;

    new = ft_create_elem(data);
    new->next = *begin_list;
    *begin_list = new;
}

void	print_t_list(t_list **begin_list)
{
    t_list	*node;

    node = *begin_list;
    while(node->next)
    {
        printf("%s|", (char *)(node->data));
        node = node->next;
    }
    printf("%s\n", (char *)(node->data));
}
void	print_int_list(t_list **begin_list)
{
    t_list	*node;

    node = *begin_list;
    while(node->next)
    {
        printf("%d|", *(int *)(node->data));
        node = node->next;
    }
    printf("%d\n", *(int *)(node->data));
}

int	ft_list_size(t_list *begin_list)
{
    int i = 0;
    if (!begin_list)
	return (0);
    i++;
    t_list	*tmp = begin_list;
    while (tmp->next)
    {
	i++;
	tmp = tmp->next;
    }
    return (i);
}

t_list	*ft_list_last(t_list *begin_list)
{
    if (!begin_list)
	return (NULL);
    t_list	*tmp = begin_list;
    while (tmp->next)
    {
	tmp = tmp->next;
    }
    return (tmp);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
    t_list	*tmp = *begin_list;
    t_list	*new = ft_create_elem(data);
    if (!tmp)
    {
	*begin_list = new;
	return;
    }
    while (tmp->next)
	tmp = tmp->next;
    tmp->next = new;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
    int		i = 0;
    t_list	*res;

    if (!size)
	return (NULL);
    res = ft_create_elem((void *) strs[i]);
    i++;
    while(i < size)
    {
	ft_list_push_front(&res, (void *)strs[i]);
	i++;
    }
    return (res);
}

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list	*tmp;

    tmp = begin_list;
    while(begin_list)
    {
	tmp = begin_list->next;
	free_fct(begin_list);
	begin_list = tmp;
    }
}

t_list	*ft_list_at(t_list *begin_list, size_t nbr)
{
    t_list	*tmp;

    tmp = begin_list;
    while(tmp && nbr)
    {
	tmp = tmp->next;
	nbr--;
    }
    return (tmp);
}

void	ft_list_reverse(t_list **begin_list)
{
    t_list	*new_head;
    int		l;

    l = ft_list_size(*begin_list);
    new_head = ft_list_at(*begin_list, l-1);
    while (l>1)
    {
	ft_list_at(*begin_list, l-1)->next = ft_list_at(*begin_list, l-2);
	l--;
    }
    (*begin_list)->next = NULL;
    *begin_list = new_head;
}

#endif
