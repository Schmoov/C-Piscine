#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, size_t nbr)
{
    t_list	*tmp;

    tmp = begin_list;
    while(tmp && nbr)
    {
	tmp = tmp->next;
	nbr--;
    }
    return (tmp);
}


int main()
{
    char *strs[3] = {"hello world", "42", "prout"};
    t_list *test = ft_list_push_strs(3, strs);
    print_t_list(&test);
    printf("Le deuxieme élément de la liste est %s\n", ft_list_at(test, 1)->data);
    printf("Si on dépasse on trouve %p", ft_list_at(test, 3));
    ft_list_clear(test, free);
}
