#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
    t_list	*last = ft_list_last(*begin_list1);

    last->next = begin_list2;
}

int main()
{
    char **strs1 = malloc(3*sizeof(char *));
    char **strs2 = malloc(3*sizeof(char *));

    strs1[0] = strdup("Wesh");
    strs1[1] = strdup("B1");
    strs1[2] = strdup("?");
    strs2[0] = strdup("00");
    strs2[1] = strdup("-42");
    strs2[2] = strdup("157");
    t_list *test1 = ft_list_push_strs(3, strs1);
    t_list *test2 = ft_list_push_strs(3, strs2);
    print_t_list(&test1);
    print_t_list(&test2);
    ft_list_merge(&test1,test2);
    print_t_list(&test1);
}
