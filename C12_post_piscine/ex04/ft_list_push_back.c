#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
    t_list	*tmp = *begin_list;
    t_list	*new = ft_create_elem(data);
    if (!tmp)
    {
	*begin_list = new;
	return;
    }
    while (tmp->next)
    {
	tmp = tmp->next;
    }
    tmp->next = new;
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
    ft_list_push_back(&test, p2);
    print_t_list(&test);
    printf("Last is:%s\n", (char *)ft_list_last(test)->data);
}
