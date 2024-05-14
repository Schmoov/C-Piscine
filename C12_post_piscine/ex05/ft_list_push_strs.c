#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
    int		i = 0;
    t_list	*res;

    if (!size)
	return (NULL);
    res = ft_create_elem((void *) strs[i]);
    i++;
    while(i < size)
    {
	ft_list_push_front(&res, (void *)strs[i]);
	i++;
    }
    return (res);
}



int main()
{
    char *strs[3] = {"hello world", "", "prout"};
    t_list *test = ft_list_push_strs(3, strs);
    print_t_list(&test);
    printf("Last is:%s\n", (char *)ft_list_last(test)->data);
}
