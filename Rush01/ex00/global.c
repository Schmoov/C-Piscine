/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanterr <rsanterr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:29:59 by rsanterr          #+#    #+#             */
/*   Updated: 2024/02/17 16:36:20 by rsanterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

#include	"global.h"


int		*grille;
int		*conditions;
int		grille_w;
int		grille_h;
int		visibilite_max;


/* 
initialisation en dur avec la chaine suivante pour le moment
	"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" 


prend en parametre la chaine qui determine les conditions
a partir de la :
- determine la taille de la grille  hauteur x largeur
- alloue le tableau des conditions : 4 x largeur (puisque c'est un carre)
- alloue la grille : largeur x hauteur
- initialise la hauteur max des caisses et donc de la visibilite : max( largeur, hauteur )
	
a partir de la chaine, on doit pouvoir determiner les dimensions : carre de N x N

on alloue les espaces (malloc) pour :
- grille : N x N int
- conditions : 4 x N int

l'espace est alloue a l'initialisation et libere avant de terminer le prog
*/
int		init_conditions(char *s)
{
/*   desactive en attendant une vraie gestion des parametres
	if (s == NULL || *s == 0)
	{
		ft_putstr("init_conditions : NULL parameters\n");
		return (254);
	}
*/

	/* dimensions en dur pour une grille de 4 x 4 en attendant d'avoir la fonction ad hoc */
	grille_w = 4;
	grille_h = 4;

	if (grille_w > grille_h)
		visibilite_max = grille_w;
	else
		visibilite_max = grille_h;
	
	grille = malloc( (grille_w * grille_h) * sizeof(int) );
	if (grille == NULL)
	{
		ft_putstr("Can't allocate grid's memory\n");
		return (250);
	}
	
	conditions = malloc( (grille_w * 4) * sizeof(int) );
	if (grille == NULL)
	{
		ft_putstr("Can't allocate condition's memory\n");
		return (250);
	}

	return (0);
}

/*
libere la memoire allouee a une grid passee en parametres
*/
int	libere_grille(int* grid)
{
	if (grid == NULL)
	{
		ft_putstr("libere_grille : NULL grid -> nothing to free\n");
		return (251);
	}
	free( grid );
	grid = NULL;
	return (0);
}

/* libere les ressources acquises lors de l'appel a init_conditions() */
int	release_conditions()
{
	libere_grille( grille );
	grille = NULL;
	
	if( conditions != NULL )
	{
		free( conditions );
		conditions = NULL;
	}
	return (0);
}
