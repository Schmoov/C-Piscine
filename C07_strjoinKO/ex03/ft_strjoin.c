/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:45:33 by parden            #+#    #+#             */
/*   Updated: 2024/02/29 18:21:30 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[0] == 0)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	get_res_length(int size, char **strs, int l_sep)
{
	int	l_res;
	int	i;

	l_res = 0;
	i = 0;
	while (i < size && (strs != NULL))
	{
		l_res += ft_strlen(strs[i]);
		i++;
	}
	l_res += (size - 1) * l_sep;
	if (l_res < 1)
		return (0);
	return (l_res);
}

// Insert word at sentence[index] returns new index
int	ft_insert(char *sentence, char *word, int index)
{
	int	i;

	i = 0;
	if (word == NULL)
		return (index);
	while (word[i])
	{
		sentence[index] = word[i];
		i++;
		index++;
	}
	return (index);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int			i;
	char		*res;
	int			l_res;
	long int	index;

	i = 0;
	index = 0;
	l_res = get_res_length(size, strs, ft_strlen(sep));
	res = (char *)malloc((l_res + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[0] = 0;
	while (i < size && (strs != NULL))
	{
		index = ft_insert(res, strs[i], index);
		if (index != (l_res - 1))
			index = ft_insert(res, sep, index);
		i++;
	}
	res[l_res] = 0;
	return (res);
}
/*
#include <unistd.h>
#include <stdio.h>
int	main()
{
	char *strs_arr[] = {"sdfsdf","","123"};
	char **strs = strs_arr;
	char *sep = "";
	char *res = ft_strjoin(3, strs, sep);
	write(1, res, ft_strlen(res));
	free(res);
}*/
