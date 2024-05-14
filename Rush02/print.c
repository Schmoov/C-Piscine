/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:08:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/25 23:10:15 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_nb_split(char **nb_split, char *dict_as_str)
{
	int		i;
	int		j;
	char	*nb_as_word;

	i = 0;
	while (nb_split[i])
	{
		nb_as_word = atoword(dict_as_str, nb_split[i]);
		j = 0;
		while (nb_as_word[j] != '\n')
			write(1, &nb_as_word[j++], 1);
		if (nb_split[i + 1])
			write(1, " ", 1);
		i++;
	}
}
