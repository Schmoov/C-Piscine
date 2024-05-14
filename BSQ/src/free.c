/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:41:07 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 17:27:32 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_double_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_struct(t_parse data)
{
	free_double_tab(data.grid);
	free(data.gui);
	free(data.map);
	free(data.first_line);
}


