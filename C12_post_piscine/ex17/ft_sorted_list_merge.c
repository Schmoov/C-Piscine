#include "ft_list.h"

int comp(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
    ft_list_merge(begin_list1, begin_list2);
    ft_list_sort(begin_list1, cmp);
    
}
int	main()
{
    int a = 0, b=1, c=20, d=33, e = 5;
    t_list *head1 = ft_create_elem(&d);
    t_list *head2 = ft_create_elem(&e);
    ft_list_push_front(&head1, &c);
    ft_list_push_front(&head2, &b);
    ft_list_push_front(&head1, &a);
    print_int_list(&head1);
    print_int_list(&head2);

    ft_sorted_list_merge(&head1, head2, comp);
    print_int_list(&head1);
}
