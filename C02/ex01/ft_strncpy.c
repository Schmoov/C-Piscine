/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:28:13 by parden            #+#    #+#             */
/*   Updated: 2024/02/15 20:19:16 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{	
		dest[i] = '\0';
		++i;
	}
	return (dest);
}
/*
#include <string.h>
int	main()
{
	char str[] = "abc";
	char str2[] = "0123456789";
	char str3[] = "0123456789";	
	str2[1] = (char) -1;
	str3[1] = (char) -1;

	ft_strncpy(str2, str, 10);
	strncpy(str3, str, 10);
	write(1, str2, 10);
	write(1, "\n", 1);
	write(1, str3, 10);
}*/
