#include <stdio.h>

void	ft_foreach(int *tab, int length, void(*f)(int))
{
    int	i;

    i=0;
    while (i<length)
    {
	f(tab[i]);
	i++;
    }
}

void	ft_putnbr(int n)
{
    printf("%d ",n);
}

int	main()
{
    int arr[5]={15,-12,42,0,12568};

    ft_foreach(arr,5, &ft_putnbr);
}
