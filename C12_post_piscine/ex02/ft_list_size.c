#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    int i = 0;
    if (!begin_list)
	return (0);
    i++;
    t_list	*tmp = begin_list;
    while (tmp->next)
    {
	i++;
	tmp = tmp->next;
    }
    return (i);
}



int main()
{
    char *str1 = "hello world";
    char *str2 = "hohoho";
    void *p1= (void *)str1;
    void *p2= (void *)str2;

    t_list *test = ft_create_elem(p1);
    print_t_list(&test);
    printf("Longueur :%d", ft_list_size(NULL));
    ft_list_push_front(&test, p2);
    print_t_list(&test);
    printf("Longueur :%d", ft_list_size(test));
    ft_list_push_front(&test, p1);
    print_t_list(&test);
    printf("Longueur :%d", ft_list_size(test));
}
