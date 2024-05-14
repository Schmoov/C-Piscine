#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX(a,b) (a>b ? a : b)

typedef struct s_btree
{
struct s_btree *left;
struct s_btree *right;
void *item;
} t_btree;

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

int	btree_level_count(t_btree *root)
{
    if (!root)
	return 0;
    return (1+ MAX(btree_level_count(root->left),btree_level_count(root->right)));
}

