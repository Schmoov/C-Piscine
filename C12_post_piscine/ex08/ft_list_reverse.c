#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
    t_list	*new_head;
    int		l;

    l = ft_list_size(*begin_list);
    new_head = ft_list_at(*begin_list, l-1);
    while (l>1)
    {
	ft_list_at(*begin_list, l-1)->next = ft_list_at(*begin_list, l-2);
	l--;
    }
    (*begin_list)->next = NULL;
    *begin_list = new_head;
}


int main()
{
    char *strs[3] = {"hello world", "42", "prout"};
    t_list *test = ft_list_push_strs(3, strs);
    print_t_list(&test);
    ft_list_reverse(&test);
    print_t_list(&test);

    ft_list_clear(test, free);
}
