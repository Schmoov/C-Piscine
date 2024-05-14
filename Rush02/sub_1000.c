/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_1000.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:23:56 by parden            #+#    #+#             */
/*   Updated: 2024/02/25 22:34:16 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ins_non_null_hundreds(char **res, char *str, int i_res, int i_str)
{
	res[i_res] = (char *)malloc(2 * sizeof(char));
	if (res[i_res] == NULL)
		return (-1);
	res[i_res][0] = str[i_str];
	res[i_res][1] = 0;
	i_res++;
	res[i_res] = (char *)malloc(4 * sizeof(char));
	if (res[i_res] == NULL)
		return (-1);
	res[i_res] = "100";
	i_res++;
	return (i_res);
}

int	ins_composite_tens(char **res, char *str, int i_res, int i_str)
{
	res[i_res] = (char *)malloc(3 * sizeof(char));
	if (res[i_res] == NULL)
		return (-1);
	res[i_res][0] = str[i_str + 1];
	res[i_res][1] = '0';
	res[i_res][2] = 0;
	i_res++;
	if (str[i_str + 2] != '0')
	{
		res[i_res] = (char *)malloc(2 * sizeof(char));
		if (res[i_res] == NULL)
			return (-1);
		res[i_res][0] = str[i_str + 2];
		res[i_res][1] = 0;
		i_res++;
	}
	return (i_res);
}

int	ins_single_word_tens(char **res, char *str, int i_res, int i_str)
{
	if (str[i_str + 1] == '1')
	{
		res[i_res] = (char *)malloc(3 * sizeof(char));
		if (res[i_res] == NULL)
			return (-1);
		res[i_res][0] = str[i_str + 1];
		res[i_res][1] = str[i_str + 2];
		res[i_res][2] = 0;
		i_res++;
	}
	else if (str[i_str + 2] != '0')
	{
		res[i_res] = (char *)malloc(2 * sizeof(char));
		if (res[i_res] == NULL)
			return (-1);
		res[i_res][0] = str[i_str + 2];
		res[i_res][1] = 0;
		i_res++;
	}
	return (i_res);
}

int	ins_readable_sub_1000(char **res, char *str, int i_res, int i_str)
{
	if (str[i_str] != '0')
	{
		i_res = ins_non_null_hundreds(res, str, i_res, i_str);
		if (i_res == -1)
			return (-1);
	}
	if (str[i_str + 1] == '0' || str[i_str + 1] == '1')
		i_res = ins_single_word_tens(res, str, i_res, i_str);
	else
		i_res = ins_composite_tens(res, str, i_res, i_str);
	return (i_res);
}
