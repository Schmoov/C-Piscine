/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:08:30 by parden            #+#    #+#             */
/*   Updated: 2024/02/22 15:44:36 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			*tab;
	long int	i;
	int			value;
	long int	spread;

	spread = ((long int) max) - ((long int) min);
	if ((spread) < 1)
	{
		*range = 0;
		return (0);
	}
	tab = (int *)malloc(spread * sizeof(int));
	if (tab == 0)
		return (-1);
	i = 0;
	value = min;
	while (i < spread)
	{
		tab[i] = value;
		value++;
		i++;
	}
	*range = tab;
	return ((int)spread);
}
/*
#include <stdio.h>
int main(int c, char**v)
{
	int max = atoi(v[2]);
	int min = atoi(v[1]);
	int	*result = ft_range(min,max);
	long int i = 0;
	printf("adress %p\n",result);
//	while (i < (((long int)max) - ((long int)min)))
//		printf("|%d", result[i++]);
	c++;
}
*/		
