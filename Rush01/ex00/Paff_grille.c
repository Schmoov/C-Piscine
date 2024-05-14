/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_grille.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanterr <rsanterr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:29:59 by rsanterr          #+#    #+#             */
/*   Updated: 2024/02/18 15:55:15 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	init_grille(int **grid)
{
	int	i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			++j;
		}
		++i;
	}
}

/* 
affiche la grille passee en paramettre sur la sortie standard 
la grille est definie comme un tableau (les colonnes) de tableau (les lignes) d'int.
*/
void	aff_grille(int **grid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = (48 + grid[i][j]);
			write(1, &c, 1);
			if (j != 4)
				write(1, " ", 1);
			++j;
		}
		write(1, "\n", 1);
		i++;
	}
}

