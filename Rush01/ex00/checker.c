/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanterr <rsanterr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:29:59 by rsanterr          #+#    #+#             */
/*   Updated: 2024/02/17 16:36:20 by rsanterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
//#include	<stdlib.h>

//#include	<stdio.h>

#include	"global.h"



/*
verifie si une grille verifie les conditions

conditions
4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2

conditions en grille
   4 3 2 1
   
4           1
3           2
2           2
1           2

   1 2 2 2   


grille 
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3

grille linearisee
1 2 3 4 2 3 4 1 3 4 1 2 4 1 2 3


*/

/* 
renvoie pour un row :
les indices gauche et droits dans la grille
la visibilite depuis la gauche et depuis la droite

utilise les variables globales
- conditions : pour les valeurs de visibilite
- grille_w et grille_h pour calculer les index

ordre des parametres de visibilite :
	col1up col2up col3up col4up 
	col1down col2down col3down col4down 
	row1left row2left row3left row4left 
	row1right row2right row3right row4right
*/
void	getrowlimits(int *cond, int row, int *left_idx, int *right_idx, int *left_vis, int *right_vis)
{
	*left_vis = cond[(2 * grille_w) + row];
	*right_vis = cond[(3 * grille_w) + row];
	
	*left_idx = (grille_w * row);
	*right_idx = (grille_w * (row + 1)) - 1;
//printf("row=%d i=[%d - %d] vis=[%d - %d] \n", row, *left_idx, *right_idx, *left_vis, *right_vis);
}

void	getcollimits(int *cond, int col, int *top_idx, int *bot_idx, int *top_vis, int *bot_vis)
{
	*top_vis = cond[col];
	*bot_vis = cond[grille_w + col];
	
	*top_idx = col;
	*bot_idx = (grille_w * (grille_h - 1)) + col;
//printf("col=%d i=[%d - %d] vis=[%d - %d] \n", col, *top_idx, *bot_idx, *top_vis, *bot_vis);
}


/*
verifie si une ligne rempli les conditions
*/
int	check_cond_row(int *grid, int *cond, int row)
{
	int	l_idx;
	int r_idx;
	int l_vis;
	int r_vis;
	int i;
	int last_height;
	int	vis_count;
	
	getrowlimits( cond, row, &l_idx, &r_idx, &l_vis, &r_vis );

	//from the LEFT
	last_height = 0;
	vis_count = 0;
	i = l_idx;
	while (i <= r_idx)
	{
//printf("       row=%d[%d] = %d  \n", row, i, grid[ i ]);
		if (grid[ i ] > last_height)
		{
			last_height = grid[ i ];
			++vis_count;
		}
		++i;
	}
	if (vis_count != l_vis)
	{
//printf("  KO row=%d left_vis=%d cond=[%d] \n", row, vis_count, l_vis);
		return (0);
	}
//printf("  OK row=%d left_vis=%d\n", row, vis_count);

	//from the RIGHT
	last_height = 0;
	vis_count = 0;
	i = r_idx;
	while (i >= l_idx)
	{
//printf("       row=%d[%d] = %d  \n", row, i, grid[ i ]);
		if (grid[ i ] > last_height)
		{
			last_height = grid[ i ];
			++vis_count;
		}
		--i;
	}
	if (vis_count != r_vis)
	{
//printf("  KO row=%d right_vis=%d cond=[%d] \n", row, vis_count, r_vis);
		return (0);
	}
//printf("  OK row=%d right_vis=%d \n", row, vis_count);
	return (1);
}

int	check_cond_col(int *grid, int *cond, int col)
{
	int	top_idx;
	int bot_idx;
	int top_vis;
	int bot_vis;
	int i;
	int last_height;
	int	vis_count;
	
	getcollimits( cond, col, &top_idx, &bot_idx, &top_vis, &bot_vis );



	//from the TOP
	last_height = 0;
	vis_count = 0;
	i = top_idx;
	while (i <= bot_idx)
	{
//printf("       col=%d[%d] = %d  \n", col, i, grid[ i ]);
		if (grid[ i ] > last_height)
		{
			last_height = grid[ i ];
			++vis_count;
		}
		i += grille_h;
	}
	if (vis_count != top_vis)
	{
//printf("  KO col=%d top_vis=%d cond=[%d] \n", col, vis_count, top_vis);
		return (0);
	}
//printf("  OK col=%d top_vis=%d\n", col, vis_count);

	//from the BOTTOM
	last_height = 0;
	vis_count = 0;
	i = bot_idx;
	while (i >= top_idx)
	{
//printf("       col=%d[%d] = %d  \n", col, i, grid[ i ]);
		if (grid[ i ] > last_height)
		{
			last_height = grid[ i ];
			++vis_count;
		}
		i -= grille_h;
	}
	if (vis_count != bot_vis)
	{
//printf("  KO col=%d bot_vis=%d cond=[%d] \n", col, vis_count, bot_vis);
		return (0);
	}
//printf("  OK col=%d bot_vis=%d \n", col, vis_count);
	return (1);
}


/* 
verifie que l'ensemble des conditions sont remplies sur une grille 
commence par verifier les conditions en ligne
avant de faire celles en colonnes

parametres :
- g : la grille
- c : les conditions

variables gloables utilisees :
- grille_h, grille_w

renvoie :
0 si une des conditions n'est pas remplie
1 si l'ensemble des conditions sont remplies
*/
int	check_conditions(int *grid, int *cond)
{
	int	col;
	int row;
	
	row = 0;
	while (row < grille_h)
	{
		if (check_cond_row( grid, cond, row ) == 0)
			return (0);
		++row;
	}
	col = 0;
	while (col < grille_w)
	{
		if (check_cond_col( grid, cond, col ) == 0)
			return (0);
		++col;
	}
	return (1);
}
