#include "ft_btree.h"

int flag = 1;
int vl;
int *last=&vl;


void	add_with_last(void *item)
{
    int *n = (int *)item;
    if (flag)
    {
	*last = *n;
	flag = 0;
    }
    else
    {
	*n += *last;
	*last = *n;
    }
}

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
    if (root->left)
	btree_apply_suffix(root->left, (*applyf));
    if (root->right)
        btree_apply_suffix(root->right, (*applyf));
    applyf(root->item);
}

int	main()
{
    int n1 = -42, n2 = 0, n3 = 4, n4 = 78, n5 = -1, n6 = 8, n7 =420;
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
    btree_apply_suffix(test1, add_with_last);
    print_int_tree(&test1);
}
