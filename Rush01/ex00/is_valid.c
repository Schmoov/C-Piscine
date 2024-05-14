/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:21:07 by parden            #+#    #+#             */
/*   Updated: 2024/02/18 16:49:20 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	is_valid_line(int **grid, int line, int c1, int c2);
int	is_valid_col(int **grid, int col, int c1, int c2);

int	is_valid_full(int **grid, int *tab_c)
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
		i++;
	}
	i = 0;
	while (i < 4)
	{
		c1 = tab_c[0 + i];
		c2 = tab_c[4 + i];
		is_v *= is_valid_col(grid, i, c1, c2);
		i++;
	}
	return (is_v);
}
