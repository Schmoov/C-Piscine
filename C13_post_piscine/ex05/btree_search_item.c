#include "ft_btree.h"

int is_sup(void *a, void *b)
{
    return ((*(int *)a - *(int *)b) >= 0);
}

void	*btree_search_item(t_btree *root, void *data_ref,
			    int (*cmpf)(void *, void *))
{
    if (!root)
	return NULL;
    if (btree_search_item(root->left, data_ref, cmpf))
	return (btree_search_item(root->left, data_ref, cmpf));
    if (cmpf(data_ref, root->item))
	return ((void *)root);
    return (btree_search_item(root->right, data_ref, cmpf));
    
}

int	main()
{
    int n1 = 0, n2 = -42, n3 = -50, n4 = 69, n5 = -1, n6 =-700, n7 =-420;
    t_btree	*test1 = btree_create_node((void *)&n1);
    t_btree	*test2 = btree_create_node((void *)&n2);
    t_btree	*test3 = btree_create_node((void *)&n3);
    t_btree	*test4 = btree_create_node((void *)&n4);
    t_btree	*test5 = btree_create_node((void *)&n5);
    t_btree	*test6 = btree_create_node((void *)&n6);
    t_btree	*test7 = btree_create_node((void *)&n7);

    test1->left = test2;
    test1->right = test3;
    test2->left = test4;
    test2->right = test5;
    test3->left = test6;
    test3->right = test7;

    int data = -1000;
    print_int_tree(&test1);
    printf("\n\n-_-_-_-_-_-_-_-_-_\n\n");
    printf("On a trouvé le node : %p", btree_search_item(test1, &data, is_sup));
}
