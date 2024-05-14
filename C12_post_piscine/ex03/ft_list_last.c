#include "ft_list.h"

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



int main()
{
    char *str1 = "hello world";
    char *str2 = "hohoho";
    void *p1= (void *)str1;
    void *p2= (void *)str2;

    t_list *test = ft_create_elem(p1);
    print_t_list(&test);
    printf("Last is:%s\n", (char *)ft_list_last(test)->data);
    ft_list_push_front(&test, p2);
    print_t_list(&test);
    printf("Last is:%s\n", (char *)ft_list_last(test)->data);
    ft_list_push_front(&test, p1);
    print_t_list(&test);
    printf("Last is:%s\n", (char *)ft_list_last(test)->data);
}
