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

#endif
