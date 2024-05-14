#include "ft_list.h"


void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list	*i;
    t_list	*j;

    if (!(*begin_list))
	return;
    i = *begin_list;
    if (!(i->next))
	return;
    j = i->next;
    while(j && (*cmp)(i->data, j->data)<0)
    {
	i = j;
	j = j->next;
    }
    if(j)
    {
	i->next = j->next;
	j->next = *begin_list;
	*begin_list = j;
	ft_list_sort(begin_list, cmp);
    }
}

int main()
{
    char **strs1 = malloc(10*sizeof(char *));

    strs1[0] = strdup("AA");
    strs1[1] = strdup("1B");
    strs1[2] = strdup("AB");
    strs1[3] = strdup("00");
    strs1[4] = strdup("1-42");
    strs1[5] = strdup("157");
    strs1[6] = strdup("2B");
    strs1[7] = strdup("A");
    strs1[8] = strdup("100");
    strs1[9] = strdup("142");
    t_list *test1 = ft_list_push_strs(10, strs1);
    print_t_list(&test1);
    ft_list_sort(&test1, strcmp);
    print_t_list(&test1);
    ft_list_clear(test1, free);
    free(strs1);
}
