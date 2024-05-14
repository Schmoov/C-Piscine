/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:46:39 by parden            #+#    #+#             */
/*   Updated: 2024/02/19 21:31:46 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	l_dest;

	i = 0;
	while (dest[i])
		i++;
	l_dest = i;
	i = 0;
	while (src[i] && nb)
	{
		dest[i + l_dest] = src[i];
		i++;
		nb--;
	}
	dest[i + l_dest] = 0;
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char**av)
{

	char* i = ft_strncat(av[1], av[2],(unsigned int)atoi(av[3]));
	char* j = strncat(av[1], av[2], (unsigned int) atoi(av[3]));
	ac++;
	printf("%s\n",i);
	printf("%s\n",j);
}*/
