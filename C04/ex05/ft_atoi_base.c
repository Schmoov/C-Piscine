/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:01:15 by parden            #+#    #+#             */
/*   Updated: 2024/02/22 12:05:29 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	is_valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '+' || str[i] == '-' || str[i] <= ' ' || str[i] > '~')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	find_char_pos(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			sign;
	long int	res;
	int			l_base;

	i = 0;
	sign = 1;
	res = 0;
	l_base = is_valid_base(base);
	if (l_base < 2)
		return (0);
	while (ft_is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (find_char_pos(str[i], base) != -1))
	{
		res = (res * l_base) + (find_char_pos(str[i], base));
		i++;
	}
	return ((int)(sign * res));
}
/*
#include <stdio.h>
int	main(int c, char**v)
{
	int n = ft_atoi_base(v[1], v[2]);
	printf("on trouve %d \n", n);
	c++;
}*/
