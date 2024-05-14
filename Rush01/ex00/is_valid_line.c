/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:21:07 by parden            #+#    #+#             */
/*   Updated: 2024/02/18 16:13:10 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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

int is_valid_line(int **grid, int line, int cl2r, int cr2l)
{
	int is_v;

	is_v = check_sudoku_line(grid, line);
	is_v *= check_sky_line_l2r(grid, line, cl2r);
	is_v *= check_sky_line_r2l(grid, line, cr2l);
	return (is_v);
}
