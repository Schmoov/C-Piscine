/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:21:07 by parden            #+#    #+#             */
/*   Updated: 2024/02/18 15:54:40 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	tab_c[16] = {4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2};

void	aff_grille(int **grid);

void	init_grille(int **grid);

int	check_sudoku_line(int **grid, int line)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (grid[line][i] == grid[line][j])
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	check_sudoku_col(int **grid, int col)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (grid[i][col] == grid[j][col])
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	check_sky_line_l2r(int **grid, int line, int constraint)
{
	int i;
	int sky_seen;
	int tallest_sky_yet;

	i = 0;
	sky_seen = 0;
	tallest_sky_yet = 0;
	while (i < 4)
	{
		if (grid[line][i] > tallest_sky_yet)
		{
			sky_seen++;
			tallest_sky_yet = grid[line][i];
		}
		i++;
	}
	if (sky_seen == constraint)
		return (1);
	else
		return (0);
}

int	check_sky_line_r2l(int **grid, int line, int constraint)
{
	int i;
	int sky_seen;
	int tallest_sky_yet;

	i = 3;
	sky_seen = 0;
	tallest_sky_yet = 0;
	while (i >= 0)
	{
		if (grid[line][i] > tallest_sky_yet)
		{
			sky_seen++;
			tallest_sky_yet = grid[line][i];
		}
		i--;
	}
	if (sky_seen == constraint)
		return (1);
	else
		return (0);
}

int	check_sky_col_t2b(int **grid, int col, int constraint)
{
	int i;
	int sky_seen;
	int tallest_sky_yet;

	i = 0;
	sky_seen = 0;
	tallest_sky_yet = 0;
	while (i < 4)
	{
		if (grid[i][col] > tallest_sky_yet)
		{
			sky_seen++;
			tallest_sky_yet = grid[i][col];
		}
		i++;
	}
	if (sky_seen == constraint)
		return (1);
	else
		return (0);
}

int	check_sky_col_b2t(int **grid, int col, int constraint)
{
	int i;
	int sky_seen;
	int tallest_sky_yet;

	i = 3;
	sky_seen = 0;
	tallest_sky_yet = 0;
	while (i >= 0)
	{
		if (grid[i][col] > tallest_sky_yet)
		{
			sky_seen++;
			tallest_sky_yet = grid[i][col];
		}
		i--;
	}
	if (sky_seen == constraint)
		return (1);
	else
		return (0);
}

int is_valid_line(int **grid, int line, int cl2r, int cr2l)
{
	int is_v;

	is_v = check_sudoku_line(grid, line);
	is_v *= check_sky_line_l2r(grid, line, cl2r);
	is_v *= check_sky_line_r2l(grid, line, cr2l);
	return (is_v);
}

int is_valid_col(int **grid, int col, int ct2b, int cb2t)
{
	int is_v;

	is_v = check_sudoku_col(grid, col);
	is_v *= check_sky_line_l2r(grid, col, ct2b);
	is_v *= check_sky_line_r2l(grid, col, cb2t);
	return (is_v);
}

	

//Assumes grid is filled with non zero elements
//and checks if grid is a valid solution to the constraints

int	is_valid_full(int **grid, int *tab_constraints)
{
	int is_v;
	int	i;
	int c1;
	int	c2;

	is_v = 1;
	i = 0;
	while (i < 4)
	{
		c1 = tab_c[8 +i];
		c2 = tab_c[12 + i];		
		is_v *= is_valid_line(grid, i, c1, c2);
	}
	while (i < 4)
	{
		c1 = tab_c[0 + i];
		c2 = tab_c[4 + i];
		is_v *= is_valid_col(grid, i, c1, c2);
	}
	return (is_v);
}

int main()
{
    int **grid;
	int i;

	i = 0;
	grid = (int **)malloc(4 * sizeof(int*));
	while (i < 4)
	{
		grid[i] = (int *)malloc(4 * sizeof(int));
		i++;
	}
    init_grille(grid);
    aff_grille(grid);
}

