/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:54:42 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 17:24:34 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

t_parse	parse_grid(char *filepath)
{
	t_parse	parse;
/*  	parse.boool = check_everything(filepath);
	if (!parse.boool)
		exit(-1); */
	parse.map = convert_file(filepath);
	parse.first_line = parse_first_line(filepath);
	parse.gui = get_pattern(parse.first_line);
	parse.x = ft_control_rows(parse.map);
	parse.y = ft_count_rows(parse.map);
	parse.grid = str_to_grid(filepath, &parse);

	return (parse);
}
