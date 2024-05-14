/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_any.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:08:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/25 20:35:01 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "divide_and_conquer.c"
#include "teset.c"

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


int	buff_size(void)
{
	char	buff[1];
	int		b_size = 1;
	int		r_size = b_size;
	int		dict;

	dict = open("numbers.dict", O_RDONLY);
	while (read(dict, buff, 1))
		r_size++;
	close(dict);
	return (r_size);
}

int	main(int argc, char **argv)
{
	char		*nb_as_arr;
	int			fd_dict;
	size_t		size;
	char		*dict_as_str;
	char		*nb_as_word;
	char		**nb_split;
	char		*str;

	printf("%s, %s\n", argv[1], str);
	str[0] = '\0';
	ft_strcpy(str, argv[1]);	
	printf("%s", str);
	pre_zero(str);
	printf("%s\n", argv[1]);
	nb_as_arr = argv[1];
	fd_dict = open("numbers.dict", O_RDONLY);
		printf("t");
	dict_as_str = (char *)malloc(buff_size() * sizeof(char));
	if (!dict_as_str)
		return (0);
	size = read(fd_dict, dict_as_str, 1000);
	nb_split = str_to_readable_arr(nb_as_arr);
//	debug_print_nb_split(nb_split);

	while (*nb_split)
	{
		nb_as_word = atoword(dict_as_str, *nb_split);
		while (*nb_as_word != '\n')
			write(1, nb_as_word++, 1);
		write(1, " ", 1);
		nb_split++;
	}
	argc++;
	free(dict_as_str);
}
