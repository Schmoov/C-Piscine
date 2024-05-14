/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wedidit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:54:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/28 15:20:50 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_sol_coords trash_struct(void)
{
	t_sol_coords trash;

	trash.boool = 0;
	trash.x = -1;
	trash.y = -1;
	trash.size = -1;
	return (trash);
}

int	ft_min(int x, int y)
{
	if (x > y)
		return (y);
	return (x);
}


t_sol_coords	is_there_empty_square(int **mat, int size, int x, int y)
{
	int				i;
	int				j;
	t_sol_coords	res;

	i = 0;
	j = -1;
	while (++j <= (y - size))
	{
		while (i <= (x - size))
		{
			if (nb_obs_square(mat, i, j, size) == 0)
			{
				res.boool = 1;
				res.x = i;
				res.y = j;
				res.size = size;
				return (res);
			}
			i++;
		}
		i = 0;
	}
	return (trash_struct());
}

t_sol_coords	solve(int **mat, int x, int y)
{
	int				max_size;
	int				size;
	t_sol_coords	res;
	t_sol_coords	pres;

	max_size = ft_min(x, y);
	size = 1;
	res = trash_struct();
	while (size <= max_size)
	{
		pres = is_there_empty_square(mat, size, x, y);
		if (pres.boool == 0)
			return (res);
		res = pres;
		size++;
	}
	return (res);
}

void	graphic_solve(int **mat, t_parse parse)
{
	t_sol_coords	res;
	int				i;
	int				j;

	res = solve(mat, parse.x, parse.y);
	if (res.boool)
	{
		i = res.x;
		j = res.y;
		while (j < (res.y + res.size))
		{
			while (i < (res.x + res.size))
			{
				parse.grid[j][i] = parse.gui[2];
				i++;
			}
			j++;
			i = res.x;
		}
	}
}
/*
int	main(int c, char** v)
{
	int		x = 27;
	int		y = 9;
	int		j = 0;
	int 	**mat;
	//char	grid_as_arr[xfull][yfull];

	char	**grid;

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
	graphic_solve(grid, mat, x, y);
	print_grid(grid);
}
*/
