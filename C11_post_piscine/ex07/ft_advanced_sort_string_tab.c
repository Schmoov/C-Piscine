#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	meta_swap(char **p1, char **p2)
{
    char *tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int	meta_strlen(char **tab)
{
    int i = 0;
    while(tab[i])
	i++;
    return (i);
}


void	ft_sort_stab(char **tab, int l, int(*cmp)(char *, char *))
{
    int		i = 1;
    int		last_not_sorted = l-1; 
    char*	first = tab[0];
    if (l == 1 || l == 0)
	return;
    while (i!=last_not_sorted)
    {
	if (cmp(first,tab[i]) >= 0)
	{
	    i++;
	}
	else
	{
	    meta_swap(&tab[i],&tab[last_not_sorted]);
	    last_not_sorted--;
	}
    }
    if (cmp(first,tab[i])>=0)
	meta_swap(&tab[0],&tab[i]);
    else
	meta_swap(&tab[0],&tab[--i]);

    ft_sort_stab(tab, i, cmp);
    ft_sort_stab(&tab[i+1],l - i - 1, cmp);
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char*))
{
    ft_sort_stab(tab, meta_strlen(tab),cmp);
}

int rev_strcmp(char* s1, char *s2)
{
    return (-strcmp(s1,s2));
}

int	main()
{
    char *word1= "acc";
    char *word2= "aca";
    char *word3= "acx";
    char *word4= "ac";
    char *word5= "acccccc";
    char *word6= "ouz";
    char *word7= NULL;
    char **ptr = malloc(10*sizeof(char *));
    
    ptr[0]= word1;
    ptr[1]= word2;
    ptr[2]= word3;
    ptr[3]= word4;
    ptr[4]= word5;
    ptr[5]= word6;
    ptr[6]= word7;

    for(int i = 0; ptr[i]; i++)
	printf("|%s|", ptr[i]);
    ft_advanced_sort_string_tab(ptr, strcmp);
    printf("\n");
    for(int i = 0; ptr[i]; i++)
	printf("|%s|", ptr[i]);
    ft_advanced_sort_string_tab(ptr, rev_strcmp);
    printf("\n");
    for(int i = 0; ptr[i]; i++)
	printf("|%s|", ptr[i]);
}
