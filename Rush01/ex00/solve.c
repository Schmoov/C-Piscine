/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:55:35 by parden            #+#    #+#             */
/*   Updated: 2024/02/18 21:27:33 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int is_valid_full(int **grid, int *tab_c);
int	check_sudoku_line(int **grid, int line);
void    aff_grille(int **grid);

int solve(int **grid, int line, int col, int vtest, int *tab_c)
{
	int i;

	i = 1;
	grid[line][col] = vtest;
	if (line == 3 && col == 3)
	{
		aff_grille(grid);
		return (is_valid_full(grid, tab_c));
	}
	else if (col == 3)
	{
		if (check_sudoku_line(grid, line))
			return (0);
		else
			while (i <= 4)
			{
				if (solve(grid, line + 1, 0, i, tab_c))
					return (1);
				else
					i++;
			}
	}
	else
	{
		i = 1;
		while (i <= 4)
		{
			if (solve(grid, line, col + 1, i, tab_c))
				return (1);
			else
				i++;
		}
	}
	return (0);
}
