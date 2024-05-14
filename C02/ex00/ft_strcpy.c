/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:28:13 by parden            #+#    #+#             */
/*   Updated: 2024/02/12 14:56:00 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main()
{
	char str[] = "yo yo b1** () ou bien ?";
	char str2[] = "ecrivons quelque chose aui est clairement assez long";
	
	ft_strcpy(str2, str);
	write(1, str2, 23);
}*/
