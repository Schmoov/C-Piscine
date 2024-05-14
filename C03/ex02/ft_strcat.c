/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:46:39 by parden            #+#    #+#             */
/*   Updated: 2024/02/19 21:28:12 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	l_dest;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	l_dest = i;
	i = 0;
	while (src[i])
	{
		dest[i + l_dest] = src[i];
		i++;
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

	char* i = ft_strcat(av[1], av[2]);
	char* j = strcat(av[1], av[2]);
	ac++;
	printf("%s\n",i);
	printf("%s\n",j);
}*/
