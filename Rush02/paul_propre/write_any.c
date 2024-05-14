/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_any.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:08:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/25 18:39:05 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "divide_and_conquer.c"

//Some kind of ft_strstr
char	*atoword(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == to_find[j] && str[i] && to_find[j])
		{
			i++;
			j++;
		}
		if (!(to_find[j]) && (str[i] < '0' || str[i] > '9'))     //Found the correct number !
		{
			while (str[i] == ' ')
				i++;
			i++;
			while (str[i] == ' ')
				i++;
			return (&str[i]);
		}
		while (str[i] != '\n')									//Go to next line
			i++;
		i++;
		j = 0;
	}
	return (NULL);
}
/*#include <stdio.h>
void	debug_print_nb_split(char	**nb_split)
{
	while (*nb_split)
		printf("|%s|", *nb_split++);
}*/

int	main(int argc, char **argv)
{
	char		*nb_as_arr;
	int			fd_dict;
	size_t		size;
	char		*dict_as_str;
	char		*nb_as_word;
	char		**nb_split;
	int			i;

	nb_as_arr = argv[1];
	fd_dict = open("numbers.dict", O_RDONLY);
	dict_as_str = (char *)malloc(100000 * sizeof(char));
	size = read(fd_dict, dict_as_str, 100000);
	nb_split = str_to_readable_arr(nb_as_arr);
//	debug_print_nb_split(nb_split);

	while (*nb_split)
	{
		nb_as_word = atoword(dict_as_str, *nb_split);
		i = 0;
		while (nb_as_word[i] != '\n')
			write(1, &nb_as_word[i++], 1);
		write(1, " ", 1);
		nb_split++;
	}
	argc++;
}
