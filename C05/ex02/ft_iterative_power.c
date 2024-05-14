/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:15:38 by parden            #+#    #+#             */
/*   Updated: 2024/02/20 11:30:08 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	long int	res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return ((int)res);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int c, char **v)
{
	int res = ft_iterative_power(atoi(v[1]),atoi(v[2]));
	printf("%d\n", res);
	c++;
}*/
