#include "ft_list.h"

void	square(void *p2i)
{
   *(int *)p2i= *(int *)p2i * *(int *)p2i;
}

int	comp(void *a, void *b)
{
    int res = *(int *)a-*(int *)b;

    if (res>0)
	return 1;
    return 0;
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


int main()
{
    int a =0, b=2, c=-1, d =4, e= -16;
    t_list *test = ft_create_elem(&a);
    ft_list_push_front(&test,&b);
    ft_list_push_front(&test,&c);
    ft_list_push_front(&test,&d);
    ft_list_push_front(&test,&e);
    print_int_list(&test);
    ft_list_foreach_if(test, square, &a, comp);
    print_int_list(&test);

    ft_list_clear(test, free);
}
