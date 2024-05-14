#include "ft_list.h"


int	comp(void *a, void *b)
{
    int **mat = a; 
    if (mat[0][0]==100)
	return 0;
    return 1;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
    t_list	*tmp;
    t_list	*last;

    while(ft_list_find(*begin_list, data_ref, cmp))
    {
	tmp = *begin_list;
	last = NULL;
        while (cmp(tmp->data, data_ref))
	{
	    last = tmp;
	    tmp = tmp->next;
	}
	if (!last)
	{
	    *begin_list = tmp->next;
	    (*free_fct)(tmp->data);
	    free(tmp);
	}
	else
	{
	    last->next = tmp->next;
	    (*free_fct)(tmp->data);
	    free(tmp);
	}
    }
}

int main()
{
    /*
    char	*a = malloc(2*sizeof(char));
    char	*b = malloc(2*sizeof(char));
    char	*c = malloc(3*sizeof(char));
    char	*d = malloc(2*sizeof(char));
    char	*e = malloc(3*sizeof(char));
    char	*f = "~";

    a[0] = 'a';
    a[1] = 0;

    b[0] = 'w';
    b[1] = 0;

    c[0] = 'a';
    c[1] = 'a';
    c[2] = 0;

    d[0] = 'z';
    d[1] = 0;

    e[0] = 'a';
    e[1] = 'a';
    e[2] = 0;
    */

     int **arr[3];

    arr[0] = (int **)malloc(3*sizeof(int *));
    arr[1] = (int **)malloc(3*sizeof(int *));
    arr[2] = (int **)malloc(3*sizeof(int *));

    arr[0][0] = (int *)malloc(3*sizeof(int));
    arr[0][1] = (int *)malloc(3*sizeof(int));
    arr[0][2] = (int *)malloc(3*sizeof(int));

    arr[1][0] = (int *)malloc(3*sizeof(int));
    arr[1][1] = (int *)malloc(3*sizeof(int));
    arr[1][2] = (int *)malloc(3*sizeof(int));

    arr[2][0] = (int *)malloc(3*sizeof(int));
    arr[2][1] = (int *)malloc(3*sizeof(int));
    arr[2][2] = (int *)malloc(3*sizeof(int));

    for(int i = 0; i<3 ; i++){
	for(int j = 0; j<3 ; j++){
	    for(int k = 0; k<3 ; k++){
		arr[i][j][k] = 100*i + 10*j + k;
	    }
	}
    }
    t_list	*test = ft_create_elem(arr[0]);
    ft_list_push_front(&test, arr[1]);
    ft_list_push_front(&test, arr[2]);
    print_mat_list(test, 3, 3);

    ft_list_remove_if(&test, NULL, comp, free_3x3_mat);
    print_mat_list(test,3,3);
//    print_list_addrs(&test);
    ft_list_clear(test, free_3x3_mat);
}
