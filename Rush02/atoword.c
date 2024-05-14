/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoword.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:08:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/25 22:32:47 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*atoword(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == to_find[j] && str[i] && to_find[j++])
			i++;
		if (!(to_find[j]) && (str[i] < '0' || str[i] > '9'))
		{
			while (str[i] == ' ')
				i++;
			i++;
			while (str[i] == ' ')
				i++;
			return (&str[i]);
		}
		while (str[i] != '\n')
			i++;
		i++;
		j = 0;
	}
	return (NULL);
}
