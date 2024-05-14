/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:32:22 by parden            #+#    #+#             */
/*   Updated: 2024/02/15 22:08:09 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char	*dest)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
	{
		++i;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	l_src;
	unsigned int	i;

	i = 0;
	l_src = ft_strlen(src);
	if (size == 0)
		return (l_src);
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		++i;
	}
	if (size != 0)
	{
		dest[i] = '\0';
	}
	return (l_src);
}
/*
#include <bsd/string.h>
int main()
{
	unsigned int	l;
	unsigned int	l2;
	char	src[] = "sdfsdf";
	char	src2[] = "sdfsdf";
	char	dest[] = "012";
	char	dest2[] = "012";
	char 	c;
	char 	c2;
	l = ft_strlcpy(dest,src,0);
	l2 = strlcpy(dest2,src2,0);
	c = '0'+l;
	c2 = '0'+l2;
	write(1,&c,1);
	write(1,"\n",1);
	write(1,&c2,1);
	write(1,"\n",1);
	write(1,dest,3);
	write(1,"\n",1);
	write(1,dest2,3);
}*/
