#include "ft_btree.h"

#define MAX(a,b) (a>b ? a : b)

int	btree_level_count(t_btree *root)
{
    if (!root)
	return 0;
    return (1+ MAX(btree_level_count(root->left),btree_level_count(root->right)));
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
    test4->left = test6;
    test3->right = test7;

    print_int_tree(&test4);
    printf("\n\n-_-_-_-_-_-_-_-_-_\n\n");
    printf("la profondeur est : %d", btree_level_count(test6->right));
}
