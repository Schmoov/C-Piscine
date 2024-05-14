/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:21:07 by parden            #+#    #+#             */
/*   Updated: 2024/02/18 19:24:43 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	tab_c[16] = {4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2};
void	init_grille(int **grid);
void	aff_grille(int **grid);
int		solve(int **grid, int line, int col, int vtest, int *tab_c);

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
/*    grid[0][0] = 4;
    grid[0][1] = 1;
    grid[0][2] = 2;
    grid[0][3] = 3;
    grid[1][0] = 2;
    grid[1][1] = 3;
    grid[1][2] = 4;
    grid[1][3] = 1;
    grid[2][0] = 3;
    grid[2][1] = 4;
    grid[2][2] = 1;
    grid[2][3] = 2;
    grid[3][0] = 1;
    grid[3][1] = 2;
    grid[3][2] = 3;
    grid[3][3] = 4;
*/
    init_grille(grid);
	i = 1;
	while (i <= 4)
	{
		if (solve(grid, 0, 0, i, tab_c))
		{
			aff_grille(grid);
			return (1);
		}
		i++;
	}
	aff_grille(grid);
}
