#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct s_btree
{
struct s_btree *left;
struct s_btree *right;
void *item;
} t_btree;
