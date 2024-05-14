/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:09:45 by parden            #+#    #+#             */
/*   Updated: 2024/02/22 13:13:20 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long int	i;
	long int	n;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	n = (long int) nb;
	while (i * i <= n)
	{
		if ((n % i) == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
int ft_is_prime_bis(int nb)
{
	int i;
	long int n;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	i = 2;
	n = (long int) nb;
	while (i * i <= n)
	{
		if (ft_is_prime_bis(i))
		{
			if ((n % i) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

#include <stdlib.h>
#include <stdio.h>
int	main(int c, char**v)
{
	printf("Methode 1 %d\n",ft_is_prime(atoi(v[1])));
	c++;
//	printf("Methode 2 %d\n",ft_is_prime_bis(19997));
}*/
