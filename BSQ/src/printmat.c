//cest juste pour debug
#include <stdio.h>
void	print_mat(int **mat, int x, int y)
{
	int i = 0;
	int j = 0;

	while (j < y)
	{
		while (i < x)
			printf("%d|", mat[j][i++]);
		printf("%s","\n");
		j++;
		i = 0;
	}
}

