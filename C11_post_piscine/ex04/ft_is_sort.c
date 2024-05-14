#include <stdio.h>

int comp(int a, int b)
{
    return (a-b);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
    int i =0;

    while (i<length-1)
    {
	if (f(tab[i], tab[i+1])>=0)
	    return 0;
	i++;
    }
    return 1;
}

int main()
{
    int tab1[] = {-25,144,1786};
    int tab2[] = {-25,-144,1786};

    printf("%d\n", ft_is_sort(tab1, 3, &comp));
    printf("%d\n", ft_is_sort(tab2, 3, &comp));
}
