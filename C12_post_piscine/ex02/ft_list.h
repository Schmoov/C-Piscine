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
    printf("%s\n\n", (char *)(node->data));
}


#endif
