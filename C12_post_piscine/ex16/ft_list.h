#ifndef	FT_LIST_H
# define FT_LIST_H

#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void	print_list_addrs(t_list **begin_list)
{
    t_list	*node;

    node = *begin_list;
    while(node->next)
    {
        printf("%p|",(void *)(node));
        node = node->next;
    }
    printf("%p\n", (void *)node);
}

void	print_mat_list(t_list *head, int i_max, int j_max)
{
    t_list *node = head;

    while(node){
    int **mat = node->data;

    for(int i = 0; i<i_max ; i++){
	for(int j = 0; j<j_max ; j++){
	    printf("|%d|", mat[i][j]);}
	printf("\n");}
    printf("~~~~~~~~~~~~~~\n");
    node = node->next;
    }
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
	free_fct(begin_list->data);
	free(begin_list);
	begin_list = tmp;
    }
}

void	free_3x3_mat(void *data)
{
    int **mat = (int **)data;
    free(mat[0]);
    free(mat[1]);
    free(mat[2]);
    free(mat);

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

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list	*tmp;

    tmp = begin_list;
    while (tmp)
    {
	(*f)(tmp->data);
	tmp = tmp->next;
    }
}
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
	*data_ref, int (*cmp)())
{
    t_list	*tmp;

    tmp = begin_list;
    while (tmp)
    {
	if ((*cmp)(tmp->data, data_ref))
	    (*f)(tmp->data);
	tmp = tmp->next;
    }
}
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
    t_list	*tmp;

    tmp = begin_list;
    while (tmp && (*cmp)(tmp->data, data_ref))
    {
	tmp = tmp->next;
    }
    return tmp;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
    t_list	*tmp;
    t_list	*last;

    while(ft_list_find(*begin_list, data_ref, cmp))
    {
	tmp = *begin_list;
	last = NULL;
        while (cmp(tmp->data, data_ref))
	{
	    last = tmp;
	    tmp = tmp->next;
	}
	if (!last)
	{
	    *begin_list = tmp->next;
	    (*free_fct)(tmp->data);
	    free(tmp);
	}
	else
	{
	    last->next = tmp->next;
	    (*free_fct)(tmp->data);
	    free(tmp);
	}
    }
}
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
    t_list	*last = ft_list_last(*begin_list1);

    last->next = begin_list2;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list	*i;
    t_list	*j;

    if (!(*begin_list))
	return;
    i = *begin_list;
    if (!(i->next))
	return;
    j = i->next;
    while(j && (*cmp)(i->data, j->data)<0)
    {
	i = j;
	j = j->next;
    }
    if(j)
    {
	i->next = j->next;
	j->next = *begin_list;
	*begin_list = j;
	ft_list_sort(begin_list, cmp);
    }
}


#endif
