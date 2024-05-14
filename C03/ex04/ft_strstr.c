/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:46:39 by parden            #+#    #+#             */
/*   Updated: 2024/02/19 22:14:37 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	if (!(to_find[0]))
		return (str);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == to_find[j] && str[i] && to_find[j])
		{
			i++;
			j++;
		}
		if (!(to_find[j]))
			return (str + i - j);
		i = i + 1 - j;
		j = 0;
	}
	return (NULL);
}
/*
int	main(int ac, char**av)
{
	char* i = ft_strstr(av[1], av[2]);
	char* j = strstr(av[1], av[2]);
	ac++;
	printf("%p\n",i);
	printf("%p\n",j);
}*/
