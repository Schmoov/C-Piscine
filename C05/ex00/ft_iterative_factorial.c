/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:49:04 by parden            #+#    #+#             */
/*   Updated: 2024/02/22 12:48:31 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	long int	res;

	res = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
		res *= nb--;
	return ((int)res);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int c, char**v)
{
	printf("%d\n", ft_iterative_factorial(atoi(v[1])));
	c++;
}*/
