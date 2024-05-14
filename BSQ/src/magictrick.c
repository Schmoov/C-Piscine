/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magictrick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:24:03 by parden            #+#    #+#             */
/*   Updated: 2024/02/28 15:15:17 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**init_int_mat(int x, int y)
{
	int	**mat;
	int	j;

	j = 0;
	mat = (int **)malloc((y + 1) * sizeof(int *));
	if (!mat)
		return (NULL);
	mat[y] = NULL;
	while (j < y)
	{
		mat[j++] = (int *)malloc((x + 1) * sizeof(int));

	}
	return (mat);
}

void	fill_mat_with_zeros(int **mat, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
			mat[j][i++] = 0;
		j++;
		i = 0;
	}
}

//cest juste pour debug
/* void	print_mat(int **mat, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
			printf("%d|", mat[j][i++]);
		printf("%s","\n");
		j++;
		i = 0;
	}
} */

int	**magic_trick(char **grid, int x, int y, char *gui)
{
	int	**mat;
	int	i;
	int	j;

	i = 0;
	j = -1;
	mat = init_int_mat(x, y);
	fill_mat_with_zeros(mat, x, y);
	while (++j < y)
	{
		while (i < x)
		{
			if (j)
				mat[j][i] += mat[j - 1][i];
			if (i)
				mat[j][i] += mat[j][i - 1];
			if (i && j)
				mat[j][i] -= mat[j - 1][i - 1];
			if (grid[j][i] == gui[1])
				++(mat[j][i]);
			i++;
		}
		i = 0;
	}
	return (mat);
}
/*
int	main()
{
	int		x = 27;
	int		y = 9;
	int		i = 0;
	int		j = 0;

	char	**grid;
	int		**mat;

	grid = (char **)malloc((y + 1) * sizeof(char *));
	grid[y] = NULL;

	while (j < y)
		grid[j++] = (char *)malloc((x + 1) * sizeof(char));
	fill_grid_with_empty(grid, x, y, '.');
	grid[1][4] = 'o';
	grid[4][4] = 'o';
	grid[8][2] = 'o';
	grid[7][6] = 'o';
	grid[8][10] = 'o';
	grid[2][12] = 'o';
	grid[5][15] = 'o';
	grid[7][21] = 'o';
	print_grid(grid);
	mat = magic_trick(grid, x, y, ".ox");
	print_mat(mat, x, y);
}
*/
