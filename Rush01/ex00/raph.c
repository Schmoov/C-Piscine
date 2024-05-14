/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raph.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanterr <rsanterr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:29:59 by rsanterr          #+#    #+#             */
/*   Updated: 2024/02/17 16:36:20 by rsanterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

#include	<stdio.h>

#include	"global.h"






/* ---------------- */

int	main(int argc, char **argv)
{
	char	*param;
	int		error;
	
	error = 0;
	if (argc != 2)
	{
		ft_putstr("bad argc number\n");
		error = 255;
	}
	
	if (error == 0)
		error = init_conditions( argv[1]);		

	init_grille( grille );
	aff_grille( grille );
	
	if (error == 0)
	{
	}
	
	

	/* conditions en dur pour une grille 4x4 : "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" */
	ft_putstr("MANUAL initialisation of conditions and grid\n\n\n");
	conditions[0] = 4;
	conditions[1] = 3;
	conditions[2] = 2;
	conditions[3] = 1;
	conditions[4] = 1;
	conditions[5] = 2;
	conditions[6] = 2;
	conditions[7] = 2;
	conditions[8] = 4;
	conditions[9] = 3;
	conditions[10] = 2;
	conditions[11] = 1;
	conditions[12] = 1;
	conditions[13] = 2;
	conditions[14] = 2;
	conditions[15] = 2;


	grille[0] = 1;
	grille[1] = 2;
	grille[2] = 3;
	grille[3] = 4;
	
	grille[4] = 2;
	grille[5] = 3;
	grille[6] = 4;
	grille[7] = 1;

	grille[8] = 3;
	grille[9] = 4;
	grille[10] = 2; //1
	grille[11] = 1; //2
	
	grille[12] = 4;
	grille[13] = 1;
	grille[14] = 2;
	grille[15] = 3;

	aff_grille( grille );

	
	
	if ( check_conditions(grille, conditions) == 0)
		ft_putstr("conditions NOOOOOT  verified   KO   your are DEAD KAPUTT\n");
	else
		ft_putstr("conditions VERIFIED\n");


	release_conditions();
	
	if (error > 0)
	{
		write(1, "Error\n", 6);
		return (error);
	}
	return (error);
}


