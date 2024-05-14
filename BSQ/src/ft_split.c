/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:34:01 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 16:38:56 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

char	**ft_crea_map(int nb_rows, int nb_cols)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (nb_rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < nb_rows)
	{
		map[i] = malloc(sizeof(char) * (nb_cols + 1));
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

void	ft_fill_map(t_parse *data, char *argv)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (argv[i] != '\n')
		i++;
	i++;
	k = 0;
	while (k < data->y)
	{
		j = 0;
		while (j < data->x)
		{
			data->grid[k][j] = argv[i + j];
			j++;
		}
		data->grid[k][j] = '\0';
		i += j;
		i++;
		k++;
	}
}
