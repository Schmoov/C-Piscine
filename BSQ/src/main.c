/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:00:53 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 18:13:38 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		**mat;
	t_parse	parsed;
	int		fd;
	int		i;

	i = 0;
	if (ac < 2)
	{
		fd = open("./new_map", O_CREAT | O_RDWR | O_TRUNC, 0777);
		read_input(fd);
		parsed = parse_grid("./new_map");
		mat = magic_trick(parsed.grid, parsed.x, parsed.y, parsed.gui);
		graphic_solve(mat, parsed);
		ft_print_tab(parsed);
		free_struct(parsed);
		return (0);

	}
	while (++i < ac)
	{
		parsed = parse_grid(av[1]);
		mat = magic_trick(parsed.grid, parsed.x, parsed.y, parsed.gui);
		graphic_solve(mat, parsed);
		ft_print_tab(parsed);
		write(1, "\n", 1);
	}
	return (0);
}

