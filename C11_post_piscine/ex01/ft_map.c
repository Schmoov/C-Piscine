#include <stdio.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
    int	i;

    i=0;
    while (i<length)
    {
	tab[i] = f(tab[i]);
	i++;
    }
}

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

int	sq(int n)
{
    return (n*n);
}

int	main()
{
    int arr[5]={5,-12,42,0,12568};

    ft_foreach(arr,5, &ft_putnbr);
    ft_map(arr,5, sq);
    printf("\n");
    ft_foreach(arr,5, &ft_putnbr);

}
