#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_create_elem(void *data)
{
    t_list	*new;

    new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
	    return NULL;
    new->data = data;
    new->next = NULL;
    return	(new);
}

int main()
{
    char *string = "hello world";
    void *pr= (void *)string;
    t_list *test = ft_create_elem(pr);
    printf("%s", (char *)(test->data));
}
