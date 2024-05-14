#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
    int 	l = ft_list_size(begin_list);
    int 	i = 0;
    void	*tmp;
    while (i<l/2)
    {
	tmp = ft_list_at(begin_list, l-i-1)->data;
	ft_list_at(begin_list, l-i-1)->data = ft_list_at(begin_list, i)->data;
	ft_list_at(begin_list, i)->data = tmp;
	i++;
    }
}

int	main()
{
    int a = 0, b=1, c=2, d=3;
    t_list *head = ft_create_elem(&a);
    ft_list_push_back(&head, &b);
    ft_list_push_back(&head, &c);
//    ft_list_push_back(&head, &d);
    print_int_list(&head);
    ft_list_reverse_fun(head);
    print_int_list(&head);
}
