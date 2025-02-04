/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:46:39 by parden            #+#    #+#             */
/*   Updated: 2024/02/17 14:11:39 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && n)
	{
		i++;
		n--;
	}
	if ((s1[i] == s2[i]) || n == 0)
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	else
		return (-1);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char**av)
{
	int i = ft_strncmp(av[1], av[2],atoi(av[3]));
	int j = strncmp(av[1], av[2],atoi(av[3]));
	ac++;
	printf("%d\n",i);
	printf("%d\n",j);
}*/
