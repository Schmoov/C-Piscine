#include "ft_btree.h"

int comp (void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

void	btree_insert_data(t_btree **root, void *item, 
			    int (*cmpf)(void *, void *))
{
    t_btree	*new = btree_create_node(item);
    t_btree	*tmp = *root;

    if (!tmp)
	*root = new;

    while(tmp)
    {
	if (cmpf(new->item, tmp->item) < 0)
	{
	    if (!(tmp->left))
	    {
		tmp->left = new;
		tmp = NULL;
	    }
	    else
		tmp = tmp->left;
	}
	else
	{
	    if (!(tmp->right))
	    {
		tmp->right = new;
		tmp = NULL;
	    }
	    else
		tmp = tmp->right;
	}
    }
}

int	main()
{
    int n1 = 0, n2 = -42, n3 = 50, n4 = -69, n5 = -1, n6 = 49, n7 =420;
    t_btree	*test1 = btree_create_node((void *)&n1);
    t_btree	*test2 = btree_create_node((void *)&n2);
    t_btree	*test3 = btree_create_node((void *)&n3);
    t_btree	*test4 = btree_create_node((void *)&n4);
    t_btree	*test5 = btree_create_node((void *)&n5);
    t_btree	*test6 = btree_create_node((void *)&n6);
    t_btree	*test7 = btree_create_node((void *)&n7);
    
    t_btree	**head = malloc(sizeof(t_btree *));
    *head = NULL;
    btree_insert_data(head, &n1, &comp);
    btree_insert_data(head, &n5, &comp);
    btree_insert_data(head, &n4, &comp);
    btree_insert_data(head, &n2, &comp);
    btree_insert_data(head, &n7, &comp);
    btree_insert_data(head, &n3, &comp);
    btree_insert_data(head, &n6, &comp);

    test1->left = test2;
    test1->right = test3;
    test2->left = test4;
    test2->right = test5;
    test3->left = test6;
    test3->right = test7;

    print_int_tree(&test1);
    printf("\n\n-_-_-_-_-_-_-_-_-_\n\n");
    print_int_tree(head);
}
