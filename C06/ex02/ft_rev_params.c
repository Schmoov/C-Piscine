/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:49:32 by parden            #+#    #+#             */
/*   Updated: 2024/02/22 19:54:15 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int c, char **v)
{
	int	i;

	c--;
	while (c)
	{
		i = 0;
		while (v[c][i])
			write(1, &v[c][i++], 1);
		write(1, "\n", 1);
		c--;
	}
}
