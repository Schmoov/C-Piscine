/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_conquer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:23:56 by parden            #+#    #+#             */
/*   Updated: 2024/02/25 23:07:06 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	t_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_triple_zero(char *str)
{
	if (str[0] == '0' && str[1] == '0' && str[2] == '0')
		return (1);
	return (0);
}

size_t	get_sub_1000_readable_length(char *str)
{
	size_t	l_sub;

	l_sub = 0;
	if (is_triple_zero(str))
		return (0);
	if (str[0] != '0')
		l_sub += 2;
	if (str[1] != '0' && str[1] != '1')
	{
		l_sub++;
		if (str[2] != '0')
			l_sub++;
	}
	else if (str[1] != '0' || str[2] != '0')
		l_sub++;
	return (l_sub);
}

size_t	get_readable_arr_length(char *str)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (str[i])
	{
		length += get_sub_1000_readable_length(&str[i]);
		i += 3;
		if (str[i] && !(is_triple_zero(&str[i - 3])))
			length++;
	}
	return (length);
}

size_t	insert_non_null_hundreds(char **res, char *str, size_t i_res, size_t i_str)
{
	res[i_res] = (char *)malloc(2 * sizeof(char));
	res[i_res][0] = str[i_str];
	res[i_res][1] = 0;
	i_res++;
	res[i_res] = (char *)malloc(4 * sizeof(char));
	res[i_res] = "100";
	i_res++;
	return (i_res);
}

size_t	insert_composite_tens(char **res, char *str, size_t i_res, size_t i_str)
{
	res[i_res] = (char *)malloc(3 * sizeof(char));
	res[i_res][0] = str[i_str + 1];
	res[i_res][1] = '0';
	res[i_res][2] = 0;
	i_res++;
	if (str[i_str + 2] != '0')
	{
		res[i_res] = (char *)malloc(2 * sizeof(char));
		res[i_res][0] = str[i_str + 2];
		res[i_res][1] = 0;
		i_res++;
	}
	return (i_res);
}

size_t	insert_single_word_tens(char **res, char *str, size_t i_res, size_t i_str)
{
	if (str[i_str + 1] == '1')
	{
		res[i_res] = (char *)malloc(3 * sizeof(char));
		res[i_res][0] = str[i_str + 1];
		res[i_res][1] = str[i_str + 2];
		res[i_res][2] = 0;
		i_res++;
	}
	else if (str[i_str + 2] != '0')
	{
		res[i_res] = (char *)malloc(2 * sizeof(char));
		res[i_res][0] = str[i_str + 2];
		res[i_res][1] = 0;
		i_res++;
	}
	return (i_res);
}

size_t	insert_readable_sub_1000(char **res, char *str, size_t i_res, size_t i_str)
{
	if (str[i_str] != '0')
		i_res = insert_non_null_hundreds(res, str, i_res, i_str);
	if (str[i_str + 1] == '0' || str[i_str + 1] == '1')
		i_res = insert_single_word_tens(res, str, i_res, i_str);
	else
		i_res = insert_composite_tens(res, str, i_res, i_str);
	return (i_res);
}	

void	insert_magnitude(char **res, char *str, size_t i_res, size_t i_str)
{
	size_t	l_mag;
	size_t	i;

	l_mag = ft_strlen(&str[i_str]) + 1;
	res[i_res] = (char *)malloc((l_mag + 1) * sizeof(char));
	res[i_res][0] = '1';
	i = 1;
	while (i < l_mag)
		res[i_res][i++] = '0';
	res[i_res][i] = 0;
}

//#include <stdio.h>
char	**str_to_readable_arr(char	*str)
{
	char	**res;
	size_t	l_res;
	size_t	i_res;
	size_t	i_str;

	l_res = get_readable_arr_length(str);
	res = (char **)malloc((l_res + 1) * sizeof(char *));
	i_res = 0;
	i_str = 0;
	while (i_res < l_res)
	{
		i_res = insert_readable_sub_1000(res, str, i_res, i_str);
		i_str += 3;
		if (str[i_str] && !(is_triple_zero(&str[i_str - 3])))
		{
			insert_magnitude(res, str, i_res, i_str);
			i_res++;
		}
	}
	res[i_res] = NULL;
	return (res);
}
/*
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
	nb_split = str_to_readable_arr(nb_as_arr);
	while (*nb_split)
	{
		nb_as_word = atoword(dict_as_str, *nb_split);
		while (*nb_as_word != '\n')
			write(1, nb_as_word++, 1);
		write(1, " ", 1);
		nb_split++;
	}
}
*/
