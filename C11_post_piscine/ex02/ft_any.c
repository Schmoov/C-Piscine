#include <stdio.h>
#include <string.h>

int	ft_any(char **tab, int(*f)(char*))
{
    int i;

    i=0;
    while(tab[i])
    {
	if (f(tab[i]))
	    return (1);
	i++;
    }
    return (0);
}
int	isempty(char*str)
{
    return (!strlen(str));
}

int	istoolong(char*str)
{
    return (strlen(str)>8);
}

int	main()
{
    char* tab[6]={"oui","","42","non","jpp",NULL};

    printf("%d\n",ft_any(tab,&isempty));
    printf("%d\n",ft_any(tab,&istoolong));
    
    tab[1]= "omgomgomgomg";

    printf("%d\n",isempty(tab[1]));
    printf("%d\n",ft_any(tab,&isempty));
    printf("%d\n",ft_any(tab,&istoolong));

}
