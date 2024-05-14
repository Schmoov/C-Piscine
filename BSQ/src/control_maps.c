/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:03:07 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 12:56:54 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"bsq.h"
#include<stdlib.h>
#include<stdio.h>

int	ft_count_rows(char *map)
{
	int	i;
	int	nb_rows;

	i = 0;
	while (map[i] != '\n')
		i++;
	nb_rows = 0;
	while (map[++i] != '\0')
	{
		if (map[i] == '\n')
			nb_rows++;
	}
	return (nb_rows);
}
