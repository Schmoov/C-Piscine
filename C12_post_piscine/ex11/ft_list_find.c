#include "ft_list.h"


int	comp(void *a, void *b)
{
    int res = *(int *)a-*(int *)b;

    if (res>0)
	return 1;
    return 0;
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


int main()
{
    int a =0, b=2, c=-1, d =4, e= 16;
    t_list *test = ft_create_elem(&a);
    t_list *find;
    
    ft_list_push_front(&test,&b);
    ft_list_push_front(&test,&c);
    ft_list_push_front(&test,&d);
    ft_list_push_front(&test,&e);
    print_int_list(&test);
    print_list_addrs(&test);
    find = ft_list_find(test, &a, comp);
    print_int_list(&test);
    print_list_addrs(&test);
    printf("On trouve %p",find);
    ft_list_clear(test, free);
}
