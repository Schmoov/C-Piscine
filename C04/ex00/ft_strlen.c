/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:14:42 by parden            #+#    #+#             */
/*   Updated: 2024/02/19 13:23:36 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
/*
#include <unistd.h>
int	main(int ac, char **av)
{
	char *vide = "";
	int i = ft_strlen(vide);
	char c = i + '0';
	write(1, &c, 1);
	ac++;
}*/
