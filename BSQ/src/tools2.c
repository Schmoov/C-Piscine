/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:44:53 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 17:03:01 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

void	reverse_str(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		tmp = str[len];
		str[len] = str[i];
		str[i] = tmp;
		i++;
		len--;
	}
}

int	get_line_number(char *str)
{
	unsigned int	i;
	unsigned int	sign;
	unsigned int	result;
	unsigned int	len;

	len = ft_strlen(str) - 3;
	i = 0;
	sign = 1;
	result = 0;
	while (((str[i] >= 9) && (str[i] <= 13))
		|| (str[i] == ' ' ))
		i++;
	while ((str[i] == '-' ) || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && ((str[i] >= '0') && (str[i] <= '9')) && i < len)
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

void	ft_print_tab(t_parse data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.x)
	{
		j = 0;
		while (j < data.y)
		{
			write(1, &data.grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
