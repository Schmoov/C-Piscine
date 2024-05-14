#include "funcy_array.c"
#include <stdio.h>
#include <stdlib.h>

long	sum(int a, int b);
long	sub(int a, int b);
long	ftdiv(int a, int b);
long	mult(int a, int b);
long	mod(int a, int b);

int	op_idx(char c)
{
    if (c== '+')
	return 0;
    if (c== '-')
	return 1;
    if (c== '/')
	return 2;
    if (c== '*')
	return 3;
    if (c== '%')
	return 4;
    else
	return (-1);
}
long	doowap(int a, int b, long(*f)(int, int))
{
    return (f(a,b));
}

int	main(int ac, char **av)
{
    long	(*arr[])(int, int) = {sum,sub,ftdiv,mult,mod};
    int		op_i;
    int		a=atoi(av[1]);
    int		b=atoi(av[3]);

    op_i = op_idx(av[2][0]);

    if (op_i==2 && b==0)
    {
	printf("Stop : division by zero\n");
	return(0);
    }
    if (op_i==4 && b==0)
    {
	printf("Stop : modulo by zero\n");
	return(0);
    }

    printf("%ld",doowap(a,b,arr[op_i]));

}
