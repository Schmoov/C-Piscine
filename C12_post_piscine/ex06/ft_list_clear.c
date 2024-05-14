#include "ft_list.h"


void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list	*tmp;

    tmp = begin_list;
    while(begin_list)
    {
	tmp = begin_list->next;
	free_fct(begin_list->data);
	free(begin_list);
	begin_list = tmp;
    }
}

void	free_3x3_mat(void *data)
{
    int **mat = (int **)data;
    free(mat[0]);
    free(mat[1]);
    free(mat[2]);
    free(mat);

}

void	print_mat_list(t_list *head, int i_max, int j_max)
{
    t_list *node = head;

    while(node){
    int **mat = node->data;

    for(int i = 0; i<i_max ; i++){
	for(int j = 0; j<j_max ; j++){
	    printf("|%d|", mat[i][j]);}
	printf("\n");}
    printf("~~~~~~~~~~~~~~\n");
    node = node->next;
    }
}

int main()
{
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
    ft_list_clear(test, free_3x3_mat);
}
