/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:02:28 by parden            #+#    #+#             */
/*   Updated: 2024/02/22 12:56:23 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	i;
	long int	n;

	n = (long int)nb;
	if (nb < 1)
		return (0);
	i = 0;
	while ((i * i) < nb)
		i++;
	if ((i * i) == nb)
		return ((int)i);
	else
		return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int c, char**v)
{
	printf("%d\n",ft_sqrt(atoi(v[1])));
	c++;
}
*/	
