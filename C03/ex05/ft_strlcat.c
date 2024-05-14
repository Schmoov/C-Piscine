/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:46:39 by parden            #+#    #+#             */
/*   Updated: 2024/02/21 14:29:54 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_min(unsigned int a, unsigned int b)
{
	if (a > b)
		return (b);
	return (a);
}

unsigned int	ft_strlen(char	*dest)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		++i;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l_dest;
	unsigned int	og_size;
	unsigned int	i;

	i = 0;
	og_size = size;
	l_dest = ft_strlen(dest);
	if (size <= l_dest || size == 0)
		return (ft_strlen(src) + ft_min(size, l_dest));
	while ((size - l_dest - 1) && src[i])
	{
		dest[l_dest + i] = src[i];
		i++;
		size--;
	}
	dest[l_dest + i] = 0;
	return (ft_strlen(src) + ft_min(og_size, l_dest));
}
/*
#include <bsd/string.h>
#include <stdio.h>
int	main(int ac, char**av)
{
	char dest[10] = "pouic";
	char dest2[10] = "pouic";
	unsigned int i = ft_strlcat(dest, av[1], atoi(av[2]));
	unsigned int j = strlcat(dest2, av[1], atoi(av[2]));
	ac++;
	printf("return %d string is %s\n",i, dest);
	printf("return %d string is %s\n",j, dest2);
}*/
