/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvictoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:04:36 by bvictoir          #+#    #+#             */
/*   Updated: 2024/02/25 23:07:38 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char **av)
{
	char	**res;
	char	*dict_as_word;
	char	**nb_split;
	int		fd_dict;
	int		size;

	if (cond(ac, av) < 1)
	{
		ft_error(cond(ac, av));
		return (0);
	}
	pre_zero(av[ac - 1]);
	fd_dict = open("numbers.dict", O_RDONLY);
	dict_as_word = (char *)malloc(buff_size() * sizeof(char));
	if (!dict_as_word)
		return (0);
	res = init_str_to_readable_arr(av[ac - 1]);
	size = read(fd_dict, dict_as_word, buff_size());
	nb_split = str_to_readable_arr(res, av[ac - 1], 0, 0);
	print_nb_split(nb_split, dict_as_word);
	return (0);
}
