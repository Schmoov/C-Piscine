/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:21:07 by parden            #+#    #+#             */
/*   Updated: 2024/02/18 16:12:22 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

int is_valid_col(int **grid, int col, int ct2b, int cb2t)
{
	int is_v;

	is_v = check_sudoku_col(grid, col);
	is_v *= check_sky_col_t2b(grid, col, ct2b);
	is_v *= check_sky_col_b2t(grid, col, cb2t);
	return (is_v);
}
