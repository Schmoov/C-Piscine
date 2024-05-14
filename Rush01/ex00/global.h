/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanterr <rsanterr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:29:59 by rsanterr          #+#    #+#             */
/*   Updated: 2024/02/17 16:36:20 by rsanterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

/* grille */
extern int		*grille;
/* les conditions a remplir (obtenues depuis la ligne de commande) */
extern int		*conditions;
/* largeur de la grille */
extern int		grille_w;
/* hauteur de la grille */
extern int		grille_h;
/* visibilite max sur la grille */
extern int		visibilite_max;



extern int	ft_atoi(char *s);
extern void	ft_putstr(char *str);

/* initialise les conditions a partir de la chaine, alloue la grille et defini les variables globales */
extern int	init_conditions(char *s);
/* initialise une grille passee en parametres a 0 */
extern void	init_grille(int *grid);
/* affiche une grille passe en parametres */
extern void	aff_grille(int *grid);
/* libere la grille passee en parametres */
extern int	libere_grille(int* grid);
/* libere les ressources acquises lors de l'appel a init_conditions() */
extern int	release_conditions();

/* verifie si les conditions sont satisfaites */
extern int	check_conditions(int *grid, int *cond);


