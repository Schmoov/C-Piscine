/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_grille.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanterr <rsanterr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:29:59 by rsanterr          #+#    #+#             */
/*   Updated: 2024/02/17 16:36:20 by rsanterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

#include	"global.h"


/* 
initialise une grille passee en parametres a 0 

la grille est declaree comme suit 
int		*grille;

la grille est carree, ses dimensions sont dans les variables globales
- height
- width
*/
void	init_grille(int *grid)
{
	int		height;
	int		width;

	height = 0;
	while (height < grille_h)
	{
		width = 0;
		while (width < grille_w)
		{
			grid[(height * grille_w) + width] = 4;
			++width;
		}
		++height;
	}
}

/* 
affiche la grille passee en paramettre sur la sortie standard 
la grille est definie comme un pointeur sur un tableau de 16 elements

declaration :
	int		*grille;

appel :
	aff_grille( grille );
*/
void	aff_grille( int *grid )
{
	char	ligne[2];
	int		height;
	int		width;

	height = 0;
	while (height < grille_h)
	{
		ligne[1] = ' ';
		width = 0;
		while (width < grille_w)
		{
			ligne[0] = grid[(height * grille_w) + width] + '0';
			if (width == (grille_w-1))
				ligne[1] = '\n';
			write(1, ligne, 2);
			++width;
		}
		++height;
	}
}
