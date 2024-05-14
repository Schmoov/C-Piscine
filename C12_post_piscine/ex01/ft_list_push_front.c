#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

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

int main()
{
    char *str1 = "hello world";
    char *str2 = "hohoho";
    void *p1= (void *)str1;
    void *p2= (void *)str2;

    t_list *test = ft_create_elem(p1);
    print_t_list(&test);
    ft_list_push_front(&test, p2);
    print_t_list(&test);
    ft_list_push_front(&test, p1);
    print_t_list(&test);
}
