#include "ft_btree.h"

void funk(void *item, int cl, int is_first)
{
    int *p = item;
    *p = 100*cl + is_first;
}

void abyl(t_btree *root, void (*f)(), int cl, int isfirst)
{
    if(!root)
	return;
    f(root->item, cl, isfirst);
    abyl(root->left, f, cl + 1, isfirst);
    abyl(root->right, f, cl + 1, 0);
}
void btree_apply_by_level(t_btree *root, 
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
    abyl(root, applyf, 0, 1);
}
int	main()
{
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0;
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

    print_int_tree(&test1);
    printf("\n\n-_-_-_-_-_-_-_-_-_\n\n");
    btree_apply_by_level(test1, funk);
    print_int_tree(&test1);
}
