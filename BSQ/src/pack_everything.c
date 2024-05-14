/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:53:05 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 15:51:31 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

// verifie la longueur de chaque ligne, si une differente retourne 0, sinon 1
int	ft_control_rows(char *map)
{
	int	i;
	int	size_row;
	int	size_control;

	i = 0;
	while (map[i] != '\n')
		i++;
	size_control = 0;
	while (map[++i] != '\n')
		size_control++;
	while (map[++i] != '\0')
	{
		size_row = 0;
		while (map[i] != '\n')
		{
			size_row++;
			i++;
		}
		if (size_row != size_control)
			return (0);
	}
	return (size_row);
}

int	ft_param_valid_map(char c, char empty, char obstacle)
{
	if (c == '\n' || c == empty || c == obstacle)
		return (1);
	return (0);
}

int	ft_control_params_in_map(char *map, char empty, char obstacle)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (!ft_param_valid_map(map[i], empty, obstacle))
			return (0);
		i++;
	}
	return (1);
}

int	check_everything(char *path)
{
	char	*map;
	char	*first_line;
	char	*params;

	map = convert_file(path);
	first_line = parse_first_line(path);
	params = get_pattern(first_line);
	if (!ft_control_rows(map))
		return (0);

	else if (!ft_control_params_in_map(map, params[0], params[1]))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

char	**str_to_grid(char *file_path, t_parse *parsed)
{
	char		*map_str;

	map_str = convert_file(file_path);
	parsed->grid = ft_crea_map(parsed->x, parsed->y);
	ft_fill_map(parsed, map_str);
	free(map_str);
	return (parsed->grid);
}
