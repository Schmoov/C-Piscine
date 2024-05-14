#include "ft_list.h"

int comp(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
    ft_list_push_front(begin_list, data);
    ft_list_sort(begin_list, cmp);
    
}
int	main()
{
    int a = 0, b=1, c=20, d=33, e = 5;
    t_list *head = ft_create_elem(&d);
    ft_list_push_front(&head, &c);
    ft_list_push_front(&head, &b);
    ft_list_push_front(&head, &a);
    print_int_list(&head);
    ft_sorted_list_insert(&head, &e, comp);
    print_int_list(&head);
}
