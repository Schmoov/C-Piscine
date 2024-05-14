/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvictoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 08:45:09 by bvictoir          #+#    #+#             */
/*   Updated: 2024/02/25 14:40:51 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_error(int x)
{
	if (x == 0)
		write(2, "Error\n", 6);
	if (x == -1)
		write(2, "Dict Error\n", 11);
}

int	is_num(char *str)
{
	while (*str)
	{
		if (*str < '0' && *str > '9')
			return (0);
		str++
	}
	return (1);
}

int correct_value(char *str)
{
	if (!is_num(str))
	{
		return (0);
	}
	return (1)
}



int	cond(int ac, char **av)
{
	if (ac != 2 || ac != 3)
		return (0);
	if (!correct_value(av[ac - 1]))
		return (0);
}
