/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:15:38 by parden            #+#    #+#             */
/*   Updated: 2024/02/20 11:36:07 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int c, char **v)
{
	int res = ft_recursive_power(atoi(v[1]),atoi(v[2]));
	printf("%d\n", res);
	c++;
}*/
