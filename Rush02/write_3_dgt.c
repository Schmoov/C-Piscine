/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_3_dgt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:08:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/25 23:11:47 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

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
		if (!(to_find[j]) && (str[i] < '0' || str[i] > '9')) //Found the correct number !
		{
			while (str[i] == ' ')
				i++;
			i++;
			while (str[i] == ' ')
				i++;
			return (&str[i]);
		}
		while (str[i] != '\n')	//Go to next line
			i++;
		i++;
		j = 0;
	}
	return (NULL);
}
// nb is ALWAYS a char* of 3 digits
char	**sub_1000_split(char *nb)
{
	char	**res;
	int		l_res;
	int		i;

	if (nb[0] != '0')
		l_res += 2;
	if (nb[1] != '0' && nb[1] != '1')
		l_res++;
	l_res++;
	res = (char **)malloc((l_res + 1) * sizeof(char *));
	i = 0;
	if (nb[0] != '0')
	{
		res[i] = (char *)malloc(2 * sizeof(char));
		res[i][0] = nb[0];
		res[i][1] = 0;
		i++;
		res[i] = "100";
		i++;
	}
	if (nb[1] != '0' && nb[1] != '1')
	{
		res[i] = (char *)malloc(3 * sizeof(char));
		res[i][0] = nb[1];
		res[i][1] = '0';
		res[i][2] = 0;
		i++;
		res[i] = (char *)malloc(2 * sizeof(char));
		res[i][0] = nb[2];
		res[i][1] = 0;
		i++;
	}
	else if(nb[1] == '1')
	{
		res[i] = (char *)malloc(3 * sizeof(char));
		res[i][0] = nb[1];
		res[i][1] = nb[2];
		res[i][2] = 0;
		i++;
	}
	else
	{
		res[i] = (char *)malloc(2 * sizeof(int));
		res[i][0] = nb[2];
		res[i][1] = 0;
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	main(int argc, char **argv)
{
	char		*nb_as_arr;
	int			fd_dict;
	size_t		size;
	char		*dict_as_str;
	char		*nb_as_word;
	char		**nb_split;

	nb_as_arr = argv[1];
	fd_dict = open("numbers.dict", O_RDONLY);
	dict_as_str = (char *)malloc(100000 * sizeof(char));
	size = read(fd_dict, dict_as_str, 100000);
	nb_split = sub_1000_split(nb_as_arr);
	while (*nb_split)
	{
		nb_as_word = atoword(dict_as_str, *nb_split);
		while (*nb_as_word != '\n')
			write(1, nb_as_word++, 1);
		write(1, " ", 1);
		nb_split++;
	}
}
