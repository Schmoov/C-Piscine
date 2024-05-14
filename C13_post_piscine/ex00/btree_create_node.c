#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
    t_btree	*node = malloc(sizeof(t_btree));

    node->left = NULL;
    node->right = NULL;
    node->item = item;
    return node;
}

void	print_int_tree(t_btree **head)
{
    printf("Addr :%p\nValue :%d\nLeft->%p Right->%p",(void *)*head,*(int *)((*head)->item),(void *)(*head)->left, (void *)(*head)->right);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    if ((*head)->left)
	print_int_tree(&((*head)->left));
    if ((*head)->right)
	print_int_tree(&((*head)->right));
}

int	main()
{
    int n = -42;
    t_btree	*test = btree_create_node((void *)&n);
    print_int_tree(&test);
}
